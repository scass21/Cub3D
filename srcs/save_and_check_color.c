/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_and_check_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 06:23:58 by scass             #+#    #+#             */
/*   Updated: 2021/04/24 07:48:42 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	scv_2(t_cub *cub, int i, int j)
{
	while (i < 3)
	{
		if (ft_isdigit(cub->parser.set_col[i][j]))
		{
			while (ft_isdigit(cub->parser.set_col[i][j]))
				j++;
			cub->parser.check_color++;
		}
		while (cub->parser.set_col[i][j] != '\0' && \
				cub->parser.set_col[i][j] == ' ')
			j++;
		if (cub->parser.set_col[i][j] == '\0')
		{
			i++;
			j = 0;
			if (cub->parser.check_color > 1)
				free_exit(cub, 6);
			cub->parser.check_color = 0;
		}
		j++;
	}
}

void	save_color_value(t_cub *cub, char *line, int i, int j)
{
	cub->parser.set_col = ft_split(&line[j], ',');
	if (!cub->parser.set_col)
		free_exit(cub, 4);
	if (cub->parser.set_col[0] == NULL || cub->parser.set_col[1] == NULL || \
		cub->parser.set_col[2] == NULL)
		free_exit(cub, 6);
	scv_2(cub, i, j);
}
