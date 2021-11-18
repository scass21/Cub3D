/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:40:46 by scass             #+#    #+#             */
/*   Updated: 2021/04/16 11:54:30 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	atoi_with_limit(const char *str)
{
	int			i;
	int			res;

	i = 0;
	res = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 30000)
			break ;
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

static int	skip_num(char *line, int i)
{
	if (line[i] != 32 && line[i] != '\0')
	{
		while (line[i] >= '0' && line[i] <= '9')
			i++;
	}
	return (i);
}

void	get_resolution(t_cub *cub, char *line, int i)
{
	while ((line[i] < 48 || line[i] > 57) && line[i] != '\0')
		i++;
	if (line[i] != 32 && line[i] != '\0')
		cub->width = atoi_with_limit(&line[i]);
	i += ft_len(cub->width);
	i = skip_num(line, i);
	while ((line[i] < 48 || line[i] > 57) && line[i] != '\0')
		i++;
	if (line[i] != 32 && line[i] != '\0')
		cub->height = atoi_with_limit(&line[i]);
	i += ft_len(cub->height);
	i = skip_num(line, i);
	while (line[i])
	{
		if (line[i] != ' ')
			cub->height = -1;
		i++;
	}
	if (cub->width == -1 || cub->height == -1)
		free_exit(cub, 3);
}
