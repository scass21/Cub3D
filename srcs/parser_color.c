/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:28:19 by scass             #+#    #+#             */
/*   Updated: 2021/04/24 07:52:11 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_colors(t_cub *cub, char *line)
{
	int		x;
	int		i;
	int		j;

	x = 0;
	i = -1;
	j = 1;
	while (line[x])
	{
		if (line[x] == 'F' || line[x] == 'C')
		{
			comma_count(cub, line, j, x);
			save_color_value(cub, line, 0, x + 1);
			check_valid_col(cub, i, j);
			get_rgb(cub, line, x);
			j = -1;
			while (cub->parser.set_col[++j])
				clearing((void *)&cub->parser.set_col[j]);
			clearing((void *)&(cub->parser.set_col));
		}
		x++;
	}
}

void	comma_count(t_cub *cub, char *line, int j, int x)
{
	int		comma;

	comma = 0;
	x++;
	while (line[j])
	{
		while (line[x])
		{
			if (!(ft_isdigit(line[x])) && line[x] != ',' && line[x] != ' ')
				free_exit(cub, 6);
			x++;
		}
		if (line[j] == ',')
			comma++;
		j++;
	}
	if (comma != 2)
		free_exit(cub, 6);
}

void	check_valid_col(t_cub *cub, int i, int j)
{
	cub->parser.r = ft_atoi(cub->parser.set_col[0]);
	cub->parser.g = ft_atoi(cub->parser.set_col[1]);
	cub->parser.b = ft_atoi(cub->parser.set_col[2]);
	if (cub->parser.set_col[0] == NULL || cub->parser.set_col[1] == NULL || \
		cub->parser.set_col[2] == NULL)
		free_exit(cub, 6);
	if (cub->parser.r < 0 || cub->parser.r > 255 || cub->parser.g < 0 || \
		cub->parser.g > 255 || cub->parser.b < 0 || cub->parser.b > 255)
		free_exit(cub, 6);
}

void	get_rgb(t_cub *cub, char *line, int x)
{
	int		rgb;

	rgb = (cub->parser.r << 16) + (cub->parser.g << 8) + cub->parser.b;
	if (line[x] == 'F')
	{
		cub->parser.floor_col = rgb;
		cub->parser.floor++;
	}
	if (line[x] == 'C')
	{
		cub->parser.ceil_col = rgb;
		cub->parser.ceil++;
	}
}
