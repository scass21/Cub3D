/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 05:52:22 by scass             #+#    #+#             */
/*   Updated: 2021/04/24 13:54:30 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_cub(const char *src)
{
	char			*dest;
	size_t			i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	while (src[j])
	{
		if (src[j] == 'x' && src[j + 1] == 'p' && src[j + 2] == 'm')
			break ;
		j++;
	}
	j = j + 3;
	dest = ft_calloc(sizeof(char), (j + 1));
	if (!dest)
		return (NULL);
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
