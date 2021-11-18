/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 06:01:34 by scass             #+#    #+#             */
/*   Updated: 2021/04/21 12:46:18 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	color_data(t_cub *cub, int fd)
{
	int				i;
	int				j;
	unsigned char	buff[4];

	i = cub->height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < cub->width)
		{
			buff[0] = (unsigned char)(cub->img.data[i * cub->width + j] % 256);
			buff[1] = (unsigned char)(cub->img.data[i * cub->width + j] / 256 \
						 % 256);
			buff[2] = (unsigned char)(cub->img.data[i * cub->width + j] / 256 \
						/ 256 % 256);
			buff[3] = (unsigned char)(0);
			write(fd, buff, 4);
			j++;
		}
		i--;
	}
}

void	bmp_info(t_cub *cub, int fd)
{
	int				i;
	unsigned char	bmp_info[40];

	i = 0;
	while (i < 40)
		bmp_info[i++] = (unsigned char)(0);
	bmp_info[0] = (unsigned char)(40);
	i = cub->width;
	bmp_info[4] = (unsigned char)(i % 256);
	bmp_info[5] = (unsigned char)(i / 256 % 256);
	bmp_info[6] = (unsigned char)(i / 256 / 256 % 256);
	bmp_info[7] = (unsigned char)(i / 256 / 256 / 256);
	i = cub->height;
	bmp_info[8] = (unsigned char)(i % 256);
	bmp_info[9] = (unsigned char)(i / 256 % 256);
	bmp_info[10] = (unsigned char)(i / 256 / 256 % 256);
	bmp_info[11] = (unsigned char)(i / 256 / 256 / 256);
	bmp_info[12] = (unsigned char)(1);
	bmp_info[14] = (unsigned char)(32);
	write(fd, bmp_info, 40);
}

void	bmp_header(t_cub *cub, int fd)
{
	int				i;
	unsigned char	header[14];

	i = 0;
	while (i < 14)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	i = cub->width * cub->height * 3;
	header[2] = (unsigned char)(i % 256);
	header[3] = (unsigned char)(i / 256 % 256);
	header[4] = (unsigned char)(i / 256 / 256 % 256);
	header[5] = (unsigned char)(i / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	save_screen(t_cub *cub)
{
	int				fd;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bmp_header(cub, fd);
	bmp_info(cub, fd);
	color_data(cub, fd);
	close(fd);
	free_exit(cub, 15);
}
