/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 04:54:45 by scass             #+#    #+#             */
/*   Updated: 2021/04/22 13:31:10 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_cub		*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		free_exit(cub, 4);
	init_cub(cub);
	cub->file_to_read = argv[1];
	if (argc > 3 || argc < 2)
		free_exit(cub, 1);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) == 0 && ft_strlen(argv[2]) == 6)
			cub->save = 1;
		else
			free_exit(cub, 2);
	}
	if (argv[1][ft_strlen(argv[1]) - 4] != '.' || argv[1][ft_strlen(argv[1]) - 3] \
		!= 'c' || argv[1][ft_strlen(argv[1]) - 2] != 'u' || \
		argv[1][ft_strlen(argv[1]) - 1] != 'b')
		free_exit(cub, 0);
	cub->fd = open(argv[1], O_DIRECTORY);
	if (cub->fd != -1)
		free_exit(cub, 12);
	start_cub(cub);
	return (0);
}

void	init_cub_2(t_cub *cub)
{
	cub->parser.no = 0;
	cub->parser.so = 0;
	cub->parser.ea = 0;
	cub->parser.we = 0;
	cub->parser.sp = 0;
	cub->parser.floor = 0;
	cub->parser.ceil = 0;
	cub->key.left = 0;
	cub->key.right = 0;
	cub->key.a = 0;
	cub->key.d = 0;
	cub->key.s = 0;
	cub->key.w = 0;
	cub->spr.count = 0;
	cub->parser.lines = 0;
	cub->save = 0;
	cub->spr.order = NULL;
	cub->spr.dist = NULL;
}

void	init_cub(t_cub *cub)
{
	cub->parser.configs = 0;
	cub->file_to_read = NULL;
	cub->mlx = NULL;
	cub->win = NULL;
	cub->map = NULL;
	cub->parser.set_col = NULL;
	cub->north = NULL;
	cub->south = NULL;
	cub->east = NULL;
	cub->west = NULL;
	cub->sprite = NULL;
	cub->parser.floor_col = -1;
	cub->parser.ceil_col = -1;
	cub->width = -1;
	cub->height = -1;
	cub->count_player = 0;
	cub->parser.tmp_map = NULL;
	cub->parser.resolution = 0;
	cub->parser.skip = 0;
	cub->parser.check_color = 0;
	init_cub_2(cub);
}
