/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:44:33 by scass             #+#    #+#             */
/*   Updated: 2021/04/25 03:37:59 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_walls_2(t_cub *cub, int i, int j, char c)
{
	if (cub->map[i])
		j = ft_strlen(cub->map[i]) - 1;
	while (cub->map[i])
	{
		while (cub->map[i][j] != '0' && j != 0)
		{
			check_obj_pos(cub, i, j);
			if (cub->map[i][j] == ' ')
				cub->map[i][j] = c;
			j--;
		}
		if ((cub->map[i][j + 1] != '1' && cub->map[i][j + 1] != 'N' \
			&& cub->map[i][j + 1] != 'E' && cub->map[i][j + 1] != 'W' \
			&& cub->map[i][j + 1] != 'S' && cub->map[i][j + 1] != '2') \
			&& j != 0)
			free_exit(cub, 8);
		i++;
		if (cub->map[i])
			j = ft_strlen(cub->map[i]) - 1;
	}
}

void	check_walls(t_cub *cub, int i, int j, char c)
{
	while (cub->map[i])
	{
		while (cub->map[i][j] != '0' && cub->map[i][j] != '\0')
		{
			check_obj_pos(cub, i, j);
			if (cub->map[i][j] == ' ')
				cub->map[i][j] = c;
			j++;
		}
		if ((cub->map[i][j - 1] != '1' && cub->map[i][j - 1] != 'N' \
			&& cub->map[i][j - 1] != 'E' && cub->map[i][j - 1] != 'W' \
			&& cub->map[i][j - 1] != 'S' && cub->map[i][j - 1] != '2') \
			&& j != ft_strlen(cub->map[i]))
			free_exit(cub, 8);
		i++;
		j = 0;
	}
	check_walls_2(cub, 0, 0, c);
}

void	check_obj_pos(t_cub *cub, int i, int j)
{
	if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E' || \
		cub->map[i][j] == 'W' || cub->map[i][j] == 'S' \
		|| cub->map[i][j] == '2')
	{
		if (!(cub->map[i + 1]) || (cub->map[i][j - 1] == ' ') || \
			!(cub->map[i][j - 1]) || !(cub->map[i][j + 1]) || \
			(cub->map[i][j + 1] == ' ') || !(cub->map[i - 1]) || (i - 1) < 0)
			free_exit(cub, 7);
	}
}

void	last_check(t_cub *cub, int i, int j)
{
	check_walls(cub, 0, 0, '1');
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E' || \
			cub->map[i][j] == 'W' || cub->map[i][j] == 'S')
			{
				cub->count_player++;
				if (cub->count_player == 1)
					cub->start.plr_pos = cub->map[i][j];
				cub->start.x = j;
				cub->start.y = i;
			}
			if (cub->map[i][j++] == '2')
				cub->spr.count++;
		}
		i++;
	}
	if (cub->count_player != 1)
		free_exit(cub, 11);
}

void	check_valid_map(t_cub *cub)
{
	check_available(cub, 0, 0, 0);
	check_lines(cub);
	cub->map = ft_split(cub->parser.tmp_map, '\n');
	if (!cub->map)
		free_exit(cub, 4);
	map_valid_position(cub, 0, -1);
	check_walls(cub, 0, 0, ' ');
}
