/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:39:24 by scass             #+#    #+#             */
/*   Updated: 2021/04/25 03:08:18 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	if_value_in_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (i == ft_strlen(line))
		return (0);
	return (1);
}

int	line_is_map(t_cub *cub, char *line)
{
	if (cub->parser.configs == 8 && cub->parser.skip == 1)
	{
		if (if_value_in_line(line) == 0 && cub->parser.lines == 0)
			return (0);
		return (1);
	}
	return (0);
}

void	check_available(t_cub *cub, int i, int n, int o)
{
	int		t;

	t = 0;
	while (cub->parser.tmp_map[i])
	{
		if (cub->parser.tmp_map[i] == '\n')
			n++;
		if (cub->parser.tmp_map[i] == '1')
			o++;
		if (cub->parser.tmp_map[i] == '\t')
			t++;
		i++;
	}
	if ((n < 2 || o < 4) || t > 0)
		free_exit(cub, 7);
}

void	check_lines(t_cub *cub)
{
	int		i;

	i = ft_strlen(cub->parser.tmp_map);
	while (cub->parser.tmp_map[i] != '1')
		i--;
	while (i != 0)
	{
		if (cub->parser.tmp_map[i] == '\n' && cub->parser.tmp_map[i - 1]
			== '\n')
		{
			cub->parser.tmp_map[i] = '0';
			cub->parser.lines--;
		}
		i--;
	}
}

void	map_valid_position(t_cub *cub, int i, int j)
{
	while (cub->map[++i])
	{
		while (cub->map[i][++j])
		{
			if (!ft_strchr(" 012NEWS", cub->map[i][j]))
				free_exit(cub, 7);
			if (cub->map[i][j] == '0' && (ft_strlen(cub->map[i - 1]) - 1 < j \
				|| ft_strlen(cub->map[i + 1]) - 1 < j))
				free_exit(cub, 7);
			if (cub->map[i][j] == '0' && (cub->map[i - 1][j] == ' ' \
				|| cub->map[i + 1][j] == ' ' || cub->map[i][j - 1] == ' ' \
				|| cub->map[i][j + 1] == ' '))
				free_exit(cub, 7);
			if ((ft_strchr("2NEWS", cub->map[i][j])) && \
				(ft_strlen(cub->map[i - 1]) - 1 < j \
				|| ft_strlen(cub->map[i + 1]) - 1 < j))
				free_exit(cub, 7);
			if ((ft_strchr("2NEWS", cub->map[i][j])) && \
				(cub->map[i - 1][j] == ' ' || cub->map[i + 1][j] == ' ' || \
				cub->map[i][j - 1] == ' ' || cub->map[i][j + 1] == ' '))
				free_exit(cub, 7);
		}
		j = -1;
	}
}
