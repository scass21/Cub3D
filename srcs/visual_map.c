/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:44:22 by scass             #+#    #+#             */
/*   Updated: 2021/04/13 14:01:42 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_colors(t_cub *cub, int i, int j)
{
	while (++j < cub->height / 2)
	{
		i = -1;
		while (++i < cub->width)
			cub->img.data[j * cub->width + i] = cub->parser.ceil_col;
	}
	while (j < cub->height)
	{
		i = -1;
		while (++i < cub->width)
			cub->img.data[j * cub->width + i] = cub->parser.floor_col;
		j++;
	}
}

void	start_ray(t_cub *cub, int x)
{
	cub->dir.camerax = 2 * x / (double)cub->width - 1;
	cub->dir.ray_x = cub->dir.x + cub->dir.planex * cub->dir.camerax;
	cub->dir.ray_y = cub->dir.y + cub->dir.planey * cub->dir.camerax;
	cub->ray.mapx = (int)cub->start.x;
	cub->ray.mapy = (int)cub->start.y;
	cub->ray.deltadistx = fabs(1 / cub->dir.ray_x);
	cub->ray.deltadisty = fabs(1 / cub->dir.ray_y);
	step_sidedist(cub);
}

void	step_sidedist(t_cub *cub)
{
	if (cub->dir.ray_x < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.sidedistx = (cub->start.x - cub->ray.mapx) * \
								cub->ray.deltadistx;
	}
	else
	{
		cub->ray.stepx = 1;
		cub->ray.sidedistx = (cub->ray.mapx + 1.0 - cub->start.x) * \
								cub->ray.deltadistx;
	}
	if (cub->dir.ray_y < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.sidedisty = (cub->start.y - cub->ray.mapy) * \
								cub->ray.deltadisty;
	}
	else
	{
		cub->ray.stepy = 1;
		cub->ray.sidedisty = (cub->ray.mapy + 1.0 - cub->start.y) * \
								cub->ray.deltadisty;
	}
}

void	hit_wall(t_cub *cub)
{
	cub->ray.hit = 0;
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sidedistx <= cub->ray.sidedisty)
		{
			cub->ray.sidedistx += cub->ray.deltadistx;
			cub->ray.mapx += cub->ray.stepx;
			cub->ray.side = 1;
		}
		else
		{
			cub->ray.sidedisty += cub->ray.deltadisty;
			cub->ray.mapy += cub->ray.stepy;
			cub->ray.side = 0;
		}
		if (cub->map[cub->ray.mapy][cub->ray.mapx] == '1')
			cub->ray.hit = 1;
	}
}

void	perp_wall_dist(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perpwalldist = (cub->ray.mapy - cub->start.y + \
								(1 - cub->ray.stepy) / 2) / cub->dir.ray_y;
	else
		cub->ray.perpwalldist = (cub->ray.mapx - cub->start.x + \
								(1 - cub->ray.stepx) / 2) / cub->dir.ray_x;
}
