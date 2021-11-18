/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:34:01 by scass             #+#    #+#             */
/*   Updated: 2021/04/14 02:35:14 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_handler(t_cub *cub)
{
	int		i;

	i = 0;
	while (i < cub->spr.count)
	{
		set_sprite_param(cub, i, 0);
		draw_sprite(cub);
		i++;
	}
}

void	draw_sprite_2(t_cub *cub, int i, int cal)
{
	if (cub->drw.startx < cub->width && cub->spr.transy > 0 && \
		cub->drw.startx > 0 && cub->spr.transy < cub->zbuffer[cub->drw.startx])
	{
		while (++i < cub->drw.endy && i < cub->height)
		{
			cal = i * 256 - cub->height * 128 + cub->drw.spr_h * 128;
			cub->drw.y = (int)((cal * cub->drw.sp_h) / cub->drw.spr_h) / 256;
			if (cub->drw.x < 0)
				cub->drw.x = 0;
			if (cub->drw.y < 0)
				cub->drw.y = 0;
			if (cub->drw.sp_w * cub->drw.y + cub->drw.x < cub->drw.sp_w * \
				cub->drw.sp_h)
				cub->color = cub->img.data_sprite[cub->drw.sp_w * \
						cub->drw.y + cub->drw.x];
			if (cub->color != 0 && cub->width * \
				cub->height > i * cub->width + cub->drw.startx)
				cub->img.data[i * cub->width + cub->drw.startx] = cub->color;
		}
	}
}

void	draw_sprite(t_cub *cub)
{
	if (cub->drw.starty < 0)
		cub->drw.starty = 0;
	cub->drw.endy = cub->drw.spr_h / 2 + cub->height / 2;
	if (cub->drw.starty >= cub->height)
		cub->drw.starty = cub->height - 1;
	cub->drw.spr_w = cub->height / cub->spr.transy;
	cub->drw.startx = -cub->drw.spr_w / 2 + cub->spr.screen;
	if (cub->drw.startx < 0)
		cub->drw.startx = 0;
	cub->drw.endx = cub->drw.spr_w / 2 + cub->spr.screen;
	if (cub->drw.endx >= cub->width)
		cub->drw.endx = cub->width - 1;
	while (cub->drw.startx < cub->drw.endx && cub->drw.startx < cub->width)
	{
		cub->drw.x = (int)(256 * (cub->drw.startx - (-cub->drw.spr_w / 2 \
			+ cub->spr.screen)) * cub->drw.sp_w / cub->drw.spr_w) / 256;
		if (cub->drw.x < 0)
			cub->drw.x = 0;
		if (cub->drw.y < 0)
			cub->drw.y = 0;
		draw_sprite_2(cub, cub->drw.starty, 0);
		cub->drw.startx++;
	}
}

void	set_sprite_param(t_cub *cub, int i, double inv_det)
{
	double		x;
	double		y;
	t_sprites	*spr;

	spr = malloc(sizeof(t_sprites) * (cub->spr.count + 1));
	if (!spr)
		free_exit(cub, 4);
	sorting_spr(cub, spr, -1, 0);
	x = spr[cub->spr.order[i]].x - cub->start.x;
	y = spr[cub->spr.order[i]].y - cub->start.y;
	inv_det = 1.0 / (cub->dir.planex * cub->dir.y - cub->dir.x * \
		cub->dir.planey);
	cub->spr.transx = inv_det * (cub->dir.y * x - cub->dir.x * y);
	cub->spr.transy = inv_det * (-cub->dir.planey * x + \
		cub->dir.planex * y);
	cub->spr.screen = ((cub->width / 2) * (1 + cub->spr.transx / \
						cub->spr.transy));
	cub->drw.spr_h = cub->height / cub->spr.transy;
	cub->drw.starty = -cub->drw.spr_h / 2 + cub->height / 2;
	clearing((void *)&spr);
}
