/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_spr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 01:49:20 by scass             #+#    #+#             */
/*   Updated: 2021/04/21 12:47:35 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	void	spr_dist(t_cub *cub, t_sprites *spr)
{
	int		i;

	i = -1;
	while (++i < cub->spr.count)
	{
		cub->spr.order[i] = i;
		cub->spr.dist[i] = ((cub->start.x - spr[i].x) * (cub->start.x -\
			spr[i].x) + (cub->start.y - spr[i].y) * (cub->start.y - spr[i].y));
	}
}

static	void	spr_coordinate(t_cub *cub, t_sprites *spr, int i, int j)
{
	int		k;

	k = 0;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (cub->map[i][j] == '2')
			{
				spr[k].y = i + 0.5;
				spr[k++].x = j + 0.5;
			}
		}
	}
}

void	sorting_spr(t_cub *cub, t_sprites *spr, int i, int j)
{
	double	tmp;

	spr_coordinate(cub, spr, -1, -1);
	spr_dist(cub, spr);
	while (++i < cub->spr.count)
	{
		j = -1;
		while (++j < cub->spr.count - 1)
		{
			if (cub->spr.dist[j] < cub->spr.dist[j + 1])
			{
				tmp = cub->spr.order[j];
				cub->spr.order[j] = cub->spr.order[j + 1];
				cub->spr.order[j + 1] = (int)tmp;
				tmp = cub->spr.dist[j];
				cub->spr.dist[j] = cub->spr.dist[j + 1];
				cub->spr.dist[j + 1] = tmp;
			}
		}
	}
}
