/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:06:19 by scass             #+#    #+#             */
/*   Updated: 2021/04/25 03:07:18 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parsing_map(t_cub *cub, char *line)
{
	cub->fd = open(cub->file_to_read, O_RDONLY);
	if (cub->fd == -1)
		free_exit(cub, 12);
	cub->parser.tmp_map = ft_strdup("");
	if (!cub->parser.tmp_map)
		free_exit(cub, 4);
	get_conf_and_save_map(cub, line);
	check_valid_map(cub);
	handle_spaces(cub, -1, -1);
	last_check(cub, 0, -1);
}

static void	read_file(t_cub *cub, char *line)
{
	valid_value(line, cub);
	if (if_value_in_line(line) == 1)
		get_configuration(cub, line);
	if (line_is_map(cub, line) == 1)
	{
		cub->parser.tmp_map = ft_strjoin(cub->parser.tmp_map, line);
		if (!cub->parser.tmp_map)
			free_exit(cub, 4);
		cub->parser.tmp_map = ft_strjoin(cub->parser.tmp_map, "\n");
		if (!cub->parser.tmp_map)
			free_exit(cub, 4);
		cub->parser.lines++;
	}
	if (cub->parser.configs == 8 && cub->parser.skip == 0)
		cub->parser.skip++;
	clearing((void *)&line);
}

void	get_conf_and_save_map(t_cub *cub, char *line)
{
	while (get_next_line(cub->fd, &line))
		read_file(cub, line);
	if (line_is_map(cub, line) == 1)
	{
		cub->parser.tmp_map = ft_strjoin(cub->parser.tmp_map, line);
		if (!cub->parser.tmp_map)
			free_exit(cub, 4);
		cub->parser.tmp_map = ft_strjoin(cub->parser.tmp_map, "\n");
		if (!cub->parser.tmp_map)
			free_exit(cub, 4);
	}
	if (cub->parser.ceil != 1 || cub->parser.floor != 1)
		free_exit(cub, 6);
	if (cub->parser.no != -1 || cub->parser.so != -1 || cub->parser.we != -1 \
		|| cub->parser.ea != -1 || cub->parser.sp != -1)
		free_exit(cub, 5);
	clearing((void *)&line);
	close(cub->fd);
}

void	handle_spaces(t_cub *cub, int i, int j)
{
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (cub->map[i][j] == ' ' && (j - 1) == -1 && ((j + 1) <= \
				ft_strlen(cub->map[i]) && ((cub->map[i][j + 1] == ' ') || \
				(cub->map[i][j + 1] == '1'))))
				cub->map[i][j] = '1';
			else if (cub->map[i][j] == ' ' && ((j - 1) >= 0 && \
				((cub->map[i][j - 1] == ' ') || \
				((cub->map[i][j - 1] == '1')))) && ((j + 1) <= \
				ft_strlen(cub->map[i]) && ((cub->map[i][j + 1] == ' ') \
				|| (cub->map[i][j + 1] == '1'))))
				cub->map[i][j] = '1';
		}
	}
	j = 0;
	while (cub->map[0][j] != '\0')
	{
		if (cub->map[0][j] != '1')
			free_exit(cub, 8);
		j++;
	}
}
