/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:12:18 by scass             #+#    #+#             */
/*   Updated: 2021/04/18 11:41:18 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	clear_struct_next(t_cub *cub)
{
	if (cub->west)
		clearing((void *)&(cub->west));
	if (cub->sprite)
		clearing((void *)&(cub->sprite));
	if (cub->spr.order)
		clearing((void *)&(cub->spr.order));
	if (cub->spr.order)
		clearing((void *)&(cub->spr.order));
	if (cub->spr.dist)
		clearing((void *)&(cub->spr.dist));
	if (cub->zbuffer)
		clearing((void *)&(cub->zbuffer));
	if (cub->mlx)
		clearing((void *)&(cub->mlx));
}

void	clear_struct(t_cub *cub, int i)
{
	if (cub->parser.tmp_map)
		clearing((void *)&(cub->parser.tmp_map));
	if (cub->south)
		clearing((void *)&(cub->south));
	if (cub->north)
		clearing((void *)&(cub->north));
	if (cub->east)
		clearing((void *)&(cub->east));
	if (cub->map)
	{
		while (cub->map[++i])
			clearing((void *)&cub->map[i]);
		clearing((void *)&cub->map);
	}
	clear_struct_next(cub);
}

void	destroy_mlx(t_cub *cub)
{
	if (cub->mlx && cub->save == 0 && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->img.img)
		mlx_destroy_image(cub->mlx, cub->img.img);
	if (cub->img.no)
		mlx_destroy_image(cub->mlx, cub->img.no);
	if (cub->img.so)
		mlx_destroy_image(cub->mlx, cub->img.so);
	if (cub->img.ea)
		mlx_destroy_image(cub->mlx, cub->img.ea);
	if (cub->img.we)
		mlx_destroy_image(cub->mlx, cub->img.we);
	if (cub->img.sprite)
		mlx_destroy_image(cub->mlx, cub->img.sprite);
	clear_struct(cub, -1);
}

void	errors_next(t_cub *cub, int type)
{
	if (type == 9)
		ft_putstr_fd("Error\nPlayer position\n", 2);
	if (type == 10)
		ft_putstr_fd("Error\nBad map format\n", 2);
	if (type == 11)
		ft_putstr_fd("Error\nWrong number of players\n", 2);
	if (type == 12)
		ft_putstr_fd("Error\nCouldn't open the map\n", 2);
	if (type == 13)
		ft_putstr_fd("Error\nMLX function error or incorrect texture\n", 2);
	if (type == 14)
		printf("ESC was pressed, exit the program\n");
	if (type == 15)
		printf("The image is saved to a file save.bmp\n");
	if (type == 16)
		printf("Error\nInvalid values in a string\n");
	destroy_mlx(cub);
}

int	free_exit(t_cub *cub, int type)
{
	if (type == 0)
		ft_putstr_fd("Error\nInvalid map extension\n", 2);
	if (type == 1)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	if (type == 2)
		ft_putstr_fd("Error\nInvalid flag, try '--save'\n", 2);
	if (type == 3)
		ft_putstr_fd("Error\nResolution error\n", 2);
	if (type == 4)
		ft_putstr_fd("Error\nMemmory allocation error\n", 2);
	if (type == 5)
		ft_putstr_fd("Error\nConfiguration error or incorrect texture\n", 2);
	if (type == 6)
		ft_putstr_fd("Error\nInvalid color configuration\n", 2);
	if (type == 7)
		ft_putstr_fd("Error\nMap is not valid\n", 2);
	if (type == 8)
		ft_putstr_fd("Error\nMissing walls\n", 2);
	errors_next(cub, type);
	exit(0);
}
