/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_turn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 04:37:27 by scass             #+#    #+#             */
/*   Updated: 2021/04/21 12:34:01 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	turn_left(t_cub *cub)
{
	cub->dir.old_x = cub->dir.x;
	cub->dir.x = cub->dir.x * cos(-TURN) - cub->dir.y * sin(-TURN);
	cub->dir.y = cub->dir.old_x * sin(-TURN) + cub->dir.y * cos(-TURN);
	cub->dir.oldplane_x = cub->dir.planex;
	cub->dir.planex = cub->dir.planex * cos(-TURN) - \
						cub->dir.planey * sin(-TURN);
	cub->dir.planey = cub->dir.oldplane_x * sin(-TURN) + \
						cub->dir.planey * cos(-TURN);
}

void	turn_right(t_cub *cub)
{
	cub->dir.old_x = cub->dir.x;
	cub->dir.x = cub->dir.x * cos(TURN) - cub->dir.y * sin(TURN);
	cub->dir.y = cub->dir.old_x * sin(TURN) + cub->dir.y * cos(TURN);
	cub->dir.oldplane_x = cub->dir.planex;
	cub->dir.planex = cub->dir.planex * cos(TURN) - cub->dir.planey * sin(TURN);
	cub->dir.planey = cub->dir.oldplane_x * sin(TURN) + \
						cub->dir.planey * cos(TURN);
}

int	press_the_key(int key, t_cub *cub)
{
	if (key == ESC)
		free_exit(cub, 14);
	if (key == LEFT)
		cub->key.left = 1;
	if (key == RIGHT)
		cub->key.right = 1;
	if (key == A)
		cub->key.a = 1;
	if (key == D)
		cub->key.d = 1;
	if (key == S)
		cub->key.s = 1;
	if (key == W)
		cub->key.w = 1;
	return (1);
}

int	release_the_key(int key, t_cub *cub)
{
	if (key == LEFT)
		cub->key.left = 0;
	if (key == RIGHT)
		cub->key.right = 0;
	if (key == W)
		cub->key.w = 0;
	if (key == A)
		cub->key.a = 0;
	if (key == S)
		cub->key.s = 0;
	if (key == D)
		cub->key.d = 0;
	return (1);
}
