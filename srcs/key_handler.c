/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:43:30 by scass             #+#    #+#             */
/*   Updated: 2021/04/21 12:34:11 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_handler(t_cub *cub)
{
	if (cub->key.a == 1)
		move_left(cub);
	if (cub->key.d == 1)
		move_right(cub);
	if (cub->key.w == 1)
		moving_forward(cub);
	if (cub->key.s == 1)
		moving_back(cub);
	if (cub->key.right == 1)
		turn_right(cub);
	if (cub->key.left == 1)
		turn_left(cub);
	visual_map(cub, -1, -1, -1);
	return (1);
}

void	move_left(t_cub *cub)
{
	cub->start.y -= cub->dir.planey * SPEED;
	if (cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '1' || \
			cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '2')
		cub->start.y += cub->dir.planey * SPEED;
	cub->start.x -= cub->dir.planex * SPEED;
	if (cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '1' || \
			cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '2')
		cub->start.x += cub->dir.planex * SPEED;
}

void	move_right(t_cub *cub)
{
	cub->start.y += cub->dir.planey * SPEED;
	if (cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '1' || \
			cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '2')
		cub->start.y -= cub->dir.planey * SPEED;
	cub->start.x += cub->dir.planex * SPEED;
	if (cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '1' || \
			cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '2')
		cub->start.x -= cub->dir.planex * SPEED;
}

void	moving_forward(t_cub *cub)
{
	cub->start.y += cub->dir.y * SPEED;
	if (cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '1' || \
			cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '2')
		cub->start.y -= cub->dir.y * SPEED;
	cub->start.x += cub->dir.x * SPEED;
	if (cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '1' || \
			cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '2')
		cub->start.x -= cub->dir.x * SPEED;
}

void	moving_back(t_cub *cub)
{
	cub->start.y -= cub->dir.y * SPEED;
	if (cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '1' || \
			cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '2')
		cub->start.y += cub->dir.y * SPEED;
	cub->start.x -= cub->dir.x * SPEED;
	if (cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '1' || \
			cub->map[(int)(cub->start.y)][(int)(cub->start.x)] == '2')
		cub->start.x += cub->dir.x * SPEED;
}
