/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_configuration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:47:00 by scass             #+#    #+#             */
/*   Updated: 2021/04/24 15:01:37 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_configuration(t_cub *cub, char *line)
{
	config_count(cub, line, 0);
	check_resolution(cub, line, 0);
	check_texture(cub, line);
	get_colors(cub, line);
}

void	config_count(t_cub *cub, char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == 'R' || (line[i] == 'N' && line[i + 1] == 'O') || \
			(line[i] == 'S' && line[i + 1] == 'O') || (line[i] == 'W' && \
			line[i + 1] == 'E') || (line[i] == 'E' && line[i + 1] == 'A') \
			|| (line[i] == 'S' && line[i + 1] != '1' && line[i + 1] != '0') \
			|| line[i] == 'F' || line[i] == 'C')
			cub->parser.configs++;
		i++;
	}
	if (cub->parser.configs > 8)
		free_exit(cub, 5);
}

void	check_resolution(t_cub *cub, char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == 'R')
			cub->parser.resolution++;
		if (cub->parser.resolution == 1)
			if ((((!(ft_isdigit(line[i])) && line[i] != 32 && \
				line[i] != 'R') || cub->parser.resolution > 2)))
				free_exit(cub, 3);
		i++;
	}
	if (cub->parser.resolution == 1)
	{
		cub->parser.resolution++;
		get_resolution(cub, line, 0);
	}
}

void	check_texture(t_cub *cub, char *line)
{
	if (cub->parser.no == 0)
		check_texture_no(cub, line, 0);
	if (cub->parser.so == 0)
		check_texture_so(cub, line, 0);
	if (cub->parser.ea == 0)
		check_texture_ea(cub, line, 0);
	if (cub->parser.we == 0)
		check_texture_we(cub, line, 0);
	if (cub->parser.sp == 0)
		check_texture_sp(cub, line, 0);
}

void	tex_path(t_cub *cub, int i, char *line, char **s)
{
	int	fd;

	*s = ft_strdup_cub(ft_strchr(line, '.'));
	if (!s)
		free_exit(cub, 4);
	fd = open(*s, O_RDONLY);
	if (fd == -1)
		free_exit(cub, 5);
	close(fd);
	i = i + ft_strlen(*s);
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
			free_exit(cub, 5);
	}
}
