/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 01:10:57 by scass             #+#    #+#             */
/*   Updated: 2021/04/24 15:02:58 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_texture_no(t_cub *cub, char *line, int i)
{
	while (line[i] && cub->parser.no >= 0)
	{
		if (line[i] == 'N' && line[i + 1] == 'O')
		{
			cub->parser.no++;
			i += 2;
		}
		if (cub->parser.no >= 1)
			if ((line[i] != '.' && line[i] != ' ') || cub->parser.no > 1)
				free_exit(cub, 5);
		if (line[i] == '.' && cub->parser.no == 1)
		{
			tex_path(cub, i, line, &cub->north);
			cub->parser.no = -1;
		}
		i++;
	}
}

void	check_texture_ea(t_cub *cub, char *line, int i)
{
	while (line[i] && cub->parser.ea >= 0)
	{
		if (line[i] == 'E' && line[i + 1] == 'A')
		{
			cub->parser.ea++;
			i += 2;
		}
		if (cub->parser.ea >= 1)
			if ((line[i] != '.' && line[i] != ' ') || cub->parser.ea > 1)
				free_exit(cub, 5);
		if (line[i] == '.' && cub->parser.ea == 1)
		{
			tex_path(cub, i, line, &cub->west);
			cub->parser.ea = -1;
		}
		i++;
	}
}

void	check_texture_we(t_cub *cub, char *line, int i)
{
	while (line[i] && cub->parser.we >= 0)
	{
		if (line[i] == 'W' && line[i + 1] == 'E')
		{
			cub->parser.we++;
			i += 2;
		}
		if (cub->parser.we >= 1)
			if ((line[i] != '.' && line[i] != ' ') || cub->parser.we > 1)
				free_exit(cub, 5);
		if (line[i] == '.' && cub->parser.we == 1)
		{
			tex_path(cub, i, line, &cub->east);
			cub->parser.we = -1;
		}
		i++;
	}
}

void	check_texture_so(t_cub *cub, char *line, int i)
{
	while (line[i] && cub->parser.so >= 0)
	{
		if (line[i] == 'S' && line[i + 1] == 'O')
		{
			cub->parser.so++;
			i += 2;
		}
		if (cub->parser.so >= 1)
			if ((line[i] != '.' && line[i] != ' ') || cub->parser.so > 1)
				free_exit(cub, 5);
		if (line[i] == '.' && cub->parser.so == 1)
		{
			tex_path(cub, i, line, &cub->south);
			cub->parser.so = -1;
		}
		i++;
	}
}

void	check_texture_sp(t_cub *cub, char *line, int i)
{
	while (line[i] && cub->parser.sp >= 0)
	{
		if (line[i] == 'S' && line[i + 1] == ' ')
		{
			cub->parser.sp++;
			i++;
		}
		if (cub->parser.sp >= 1)
			if ((line[i] != '.' && line[i] != ' ') || cub->parser.sp > 1)
				free_exit(cub, 5);
		if (line[i] == '.' && cub->parser.sp == 1)
		{
			tex_path(cub, i, line, &cub->sprite);
			cub->parser.sp = -1;
		}
		i++;
	}
}
