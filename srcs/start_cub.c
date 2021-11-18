/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:11:02 by scass             #+#    #+#             */
/*   Updated: 2021/04/21 12:23:40 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	start_cub(t_cub *cub)
{
	parsing_map(cub, NULL);
	plr_start_position(cub);
	cub->mlx = mlx_init();
	mlx_get_screen_size(cub->mlx, &cub->user_screen_wid, &cub->user_screen_hei);
	check_screen_size(cub);
	if (cub->save == 0)
		cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
	get_walls_img(cub);
	cub->spr.order = (int *)malloc(sizeof(int) * (cub->spr.count + 1));
	if (!cub->spr.order)
		free_exit(cub, 4);
	cub->spr.dist = (double *)malloc(sizeof(double) * (cub->spr.count + 1));
	if (!cub->spr.dist)
		free_exit(cub, 4);
	cub->spr.order[cub->spr.count] = '\0';
	cub->spr.dist[cub->spr.count] = '\0';
	cub->zbuffer = malloc(sizeof(double) * cub->width);
	if (!cub->zbuffer)
		free_exit(cub, 4);
	visual_map(cub, -1, -1, -1);
	mlx_loop_hook(cub->mlx, key_handler, (void *)cub);
	mlx_loop(cub->mlx);
	free_exit(cub, 4);
}

void	check_screen_size(t_cub *cub)
{
	if (cub->user_screen_wid < cub->width)
	{
		cub->width = cub->user_screen_wid;
		printf("Error\nThe map width changed to the value");
		printf(" of your screen = %d\n", cub->width);
	}
	if (cub->width < 100)
	{
		cub->width = 100;
		printf("Error\nToo small map width has been changed to 100\n");
	}
	if (cub->user_screen_hei < cub->height)
	{
		cub->height = cub->user_screen_hei;
		printf("Error\nThe map height changed to the value");
		printf(" of your screen = %d\n", cub->height);
	}
	if (cub->height < 100)
	{
		cub->height = 100;
		printf("Error\nToo small map height has been changed to 100\n");
	}
}

void	visual_map(t_cub *cub, int i, int j, int x)
{
	put_colors(cub, i, j);
	while (++x < cub->width)
	{
		start_ray(cub, x);
		hit_wall(cub);
		perp_wall_dist(cub);
		draw_walls(cub, x);
	}
	sprite_handler(cub);
	if (cub->save == 1)
		save_screen(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	mlx_do_sync(cub->mlx);
	mlx_hook(cub->win, 2, 1L << 0, press_the_key, cub);
	mlx_hook(cub->win, 3, 1L << 1, release_the_key, cub);
	mlx_hook(cub->win, 33, 1L << 17, free_exit, cub);
}
