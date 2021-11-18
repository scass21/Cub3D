/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:19:34 by scass             #+#    #+#             */
/*   Updated: 2021/04/20 11:36:02 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	load_tex(t_cub *cub, int width, int height)
{
	cub->drw.x = (cub->drw.wall * (double)width);
	if (cub->ray.side == 0 && cub->dir.ray_y > 0)
		cub->drw.x = width - cub->drw.x - 1;
	if (cub->ray.side == 1 && cub->dir.ray_x < 0)
		cub->drw.x = width - cub->drw.x - 1;
	cub->step = 1.0 * height / cub->ray.lineheight;
	cub->drw.pos = (cub->drw.start - cub->height / 2 + \
		cub->ray.lineheight / 2) * cub->step;
}

void	set_textures(t_cub *cub)
{
	if (cub->ray.side == 1)
		cub->drw.wall = cub->start.y + cub->ray.perpwalldist * cub->dir.ray_y;
	else
		cub->drw.wall = cub->start.x + cub->ray.perpwalldist * cub->dir.ray_x;
	cub->drw.wall -= floor((cub->drw.wall));
	if (cub->ray.side == 1 && cub->ray.stepx < 0)
		load_tex(cub, cub->drw.ea_w, cub->drw.ea_h);
	if (cub->ray.side == 1 && cub->ray.stepx >= 0)
		load_tex(cub, cub->drw.we_w, cub->drw.we_h);
	if (cub->ray.side == 0 && cub->ray.stepy > 0)
		load_tex(cub, cub->drw.so_w, cub->drw.so_h);
	if (cub->ray.side == 0 && cub->ray.stepy <= 0)
		load_tex(cub, cub->drw.no_w, cub->drw.no_h);
}

void	draw_start(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		cub->drw.y = cub->ray.stepy;
		if (cub->drw.y > 0)
			cub->drw.y = (int)cub->drw.pos & (cub->drw.no_h - 1);
		else
			cub->drw.y = (int)cub->drw.pos & (cub->drw.so_h - 1);
	}
	else if (cub->ray.side == 1)
	{
		cub->drw.y = cub->ray.stepx;
		if (cub->drw.y < 0)
			cub->drw.y = ((int)cub->drw.pos & (cub->drw.ea_h - 1));
		else
			cub->drw.y = ((int)cub->drw.pos & (cub->drw.we_h - 1));
	}
}

void	draw_next(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		cub->color = cub->ray.stepy;
		if (cub->color > 0)
			cub->color = cub->img.data_so[cub->drw.no_h * cub->drw.y \
						+ cub->drw.x];
		else
			cub->color = cub->img.data_no[cub->drw.so_h * cub->drw.y \
			+ cub->drw.x];
	}
	else if (cub->ray.side == 1)
	{
		if (cub->drw.ea_h * cub->drw.y + cub->drw.x < cub->drw.ea_h * \
						cub->drw.ea_w)
		{
			cub->color = cub->ray.stepx;
			if (cub->color < 0)
				cub->color = cub->img.data_ea[cub->drw.ea_h *\
				cub->drw.y + cub->drw.x];
			else
				cub->color = cub->img.data_we[cub->drw.we_h *\
				cub->drw.y + cub->drw.x];
		}
	}
}

void	draw_walls(t_cub *cub, int x)
{
	cub->ray.lineheight = (int)(cub->height / cub->ray.perpwalldist);
	cub->drw.start = (-cub->ray.lineheight / 2) + (cub->height / 2);
	if (cub->drw.start < 0)
		cub->drw.start = 0;
	cub->drw.end = (cub->ray.lineheight / 2) + (cub->height / 2);
	if (cub->drw.end >= cub->height)
		cub->drw.end = cub->height - 1;
	set_textures(cub);
	while (cub->drw.start <= cub->drw.end)
	{
		draw_start(cub);
		draw_next(cub);
		cub->drw.pos += cub->step;
		cub->img.data[cub->drw.start++ *cub->width + x] = cub->color;
	}
	cub->zbuffer[x] = cub->ray.perpwalldist;
}
