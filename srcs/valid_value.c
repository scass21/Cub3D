/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 05:27:30 by scass             #+#    #+#             */
/*   Updated: 2021/04/24 15:11:14 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	valid_value(char *line, t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[0] != ' ' && line[0] != '\n' && line[0] != 'R' && \
			line[0] != 'N' && line[0] != 'S' && line[0] != 'W' && line[0] != 'E' \
			&& line[0] != 'S' && line[0] != 'F' && line[0] != 'C' && \
			line[0] != '1' && !((line[0] >= 9 && line[0] <= 13)))
			free_exit(cub, 16);
		if (line[0] == ' ' || line[0] == '\t')
		{
			j = 0;
			while ((line[j] == ' ' || line[j] == '\t') && line[j] != '\0')
				j++;
			if (line[j] != '1' && line[j] != '\n' && line[j] != 'R' && \
				line[j] != 'N' && line[j] != 'S' && line[j] != 'W' && line[j] != 'E' \
				&& line[j] != 'S' && line[j] != 'F' && line[j] != 'C' && \
				line[j] != '\0')
				free_exit(cub, 16);
		}
		i++;
	}	
}
