/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:38:32 by scass             #+#    #+#             */
/*   Updated: 2021/04/20 11:32:26 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_walls_img_2(t_cub *cub)
{
	cub->img.we = mlx_xpm_file_to_image(cub->mlx, cub->west, \
					&cub->drw.we_w, &cub->drw.we_h);
	if (!cub->img.we || cub->drw.we_w != 64 || cub->drw.we_h != 64)
		free_exit(cub, 13);
	cub->img.data_we = (int *)mlx_get_data_addr(cub->img.we, \
		&cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
	if (!cub->img.data_we)
		free_exit(cub, 13);
	cub->img.ea = mlx_xpm_file_to_image(cub->mlx, \
					cub->east, &cub->drw.ea_w, &cub->drw.ea_h);
	if (!cub->img.ea || cub->drw.ea_w != 64 || cub->drw.ea_h != 64)
		free_exit(cub, 13);
	cub->img.data_ea = (int *)mlx_get_data_addr(cub->img.ea, \
			&cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
	if (!cub->img.data_ea)
		free_exit(cub, 13);
	cub->img.sprite = mlx_xpm_file_to_image(cub->mlx, \
						cub->sprite, &cub->drw.sp_w, &cub->drw.sp_h);
	if (!cub->img.sprite)
		free_exit(cub, 13);
	cub->img.data_sprite = (int *)mlx_get_data_addr(cub->img.sprite, \
			&cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
	if (!cub->img.data_sprite)
		free_exit(cub, 13);
}

void	get_walls_img(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->mlx, cub->width, cub->height);
	if (!cub->img.img)
		free_exit(cub, 13);
	cub->img.data = (int *)mlx_get_data_addr(cub->img.img, \
		&cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
	if (!cub->img.data)
		free_exit(cub, 13);
	cub->img.no = mlx_xpm_file_to_image(cub->mlx, cub->north, \
		&cub->drw.no_w, &cub->drw.no_h);
	if (!cub->img.no || cub->drw.no_w != 64 || cub->drw.no_h != 64)
		free_exit(cub, 13);
	cub->img.data_no = (int *)mlx_get_data_addr(cub->img.no, \
		&cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
	if (!cub->img.data_no)
		free_exit(cub, 13);
	cub->img.so = mlx_xpm_file_to_image(cub->mlx, \
			cub->south, &cub->drw.so_w, &cub->drw.so_h);
	if (!cub->img.so || cub->drw.so_w != 64 || cub->drw.so_h != 64)
		free_exit(cub, 13);
	cub->img.data_so = (int *)mlx_get_data_addr(cub->img.so, \
		&cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
	if (!cub->img.data_so)
		free_exit(cub, 13);
	get_walls_img_2(cub);
}

void	plr_start_position_2(t_cub *cub)
{
	if (cub->start.plr_pos == 'E')
	{
		cub->dir.x = 1.0;
		cub->dir.y = 0.0;
		cub->dir.planex = 0.0;
		cub->dir.planey = 0.66;
	}
	if (cub->start.plr_pos == 'W')
	{
		cub->dir.x = -1.0;
		cub->dir.y = 0.0;
		cub->dir.planex = 0.0;
		cub->dir.planey = -0.66;
	}
}

void	plr_start_position(t_cub *cub)
{
	if (cub->start.plr_pos == 'N')
	{
		cub->dir.x = 0.0;
		cub->dir.y = -1.0;
		cub->dir.planex = 0.66;
		cub->dir.planey = 0.0;
	}
	if (cub->start.plr_pos == 'S')
	{
		cub->dir.x = 0.0;
		cub->dir.y = 1.0;
		cub->dir.planex = -0.66;
		cub->dir.planey = 0.0;
	}
	plr_start_position_2(cub);
	cub->start.x += 0.5;
	cub->start.y += 0.5;
}
