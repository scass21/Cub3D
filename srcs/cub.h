/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 00:08:01 by scass             #+#    #+#             */
/*   Updated: 2021/04/24 14:54:19 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define SPEED 0.02
# define TURN 0.02

typedef struct s_start_pos
{
	double			x;
	double			y;
	char			plr_pos;
}					t_start_pos;

typedef struct s_parser
{
	int				resolution;
	int				configs;
	int				no;
	int				so;
	int				ea;
	int				we;
	int				sp;
	int				ceil;
	int				floor;
	int				floor_col;
	int				ceil_col;
	int				check_color;
	int				lines;
	char			**set_col;
	char			*tmp_map;
	int				skip;
	int				r;
	int				g;
	int				b;
}					t_parser;

typedef struct s_dir
{
	double			x;
	double			y;
	double			old_x;
	double			planex;
	double			planey;
	double			oldplane_x;
	double			camerax;
	double			ray_x;
	double			ray_y;
}					t_dir;

typedef struct s_img
{
	void			*img;
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
	void			*sprite;
	int				*data;
	int				*data_no;
	int				*data_so;
	int				*data_we;
	int				*data_ea;
	int				*data_sprite;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
}					t_img;

typedef struct s_ray
{
	int				hit;
	int				stepy;
	int				stepx;
	double			sidedistx;
	double			sidedisty;
	int				mapx;
	int				mapy;
	double			deltadistx;
	double			deltadisty;
	int				side;
	double			perpwalldist;
	int				lineheight;
}					t_ray;

typedef struct s_draw
{
	int				start;
	int				end;
	int				startx;
	int				starty;
	int				endx;
	int				endy;
	int				x;
	int				y;
	int				no_w;
	int				no_h;
	int				so_w;
	int				so_h;
	int				we_w;
	int				we_h;
	int				ea_w;
	int				ea_h;
	int				sp_w;
	int				sp_h;
	int				spr_w;
	int				spr_h;
	double			wall;
	double			pos;
}					t_draw;

typedef struct s_sprites
{
	double			x;
	double			y;
	int				count;
	int				*order;
	double			*dist;
	int				screen;
	double			transx;
	double			transy;
}					t_sprites;

typedef struct s_key
{
	int				left;
	int				right;
	int				a;
	int				d;
	int				s;
	int				w;
}					t_key;

typedef struct s_cub
{
	t_start_pos		start;
	t_parser		parser;
	t_sprites		spr;
	t_dir			dir;
	t_img			img;
	t_key			key;
	t_ray			ray;
	t_draw			drw;
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*sprite;
	char			**map;
	int				count_player;
	int				color;
	int				fd;
	char			*file_to_read;
	int				user_screen_wid;
	int				user_screen_hei;
	int				save;
	double			*zbuffer;
	double			step;
}					t_cub;

void				start_cub(t_cub *cub);
void				init_cub(t_cub *cub);
void				check_screen_size(t_cub *cub);
void				parsing_map(t_cub *cub, char *line);
void				get_conf_and_save_map(t_cub *cub, char *line);
int					if_value_in_line(char *line);
void				get_configuration(t_cub *cub, char *line);
void				config_count(t_cub *cub, char *line, int i);
void				check_resolution(t_cub *cub, char *line, int i);
void				get_resolution(t_cub *cub, char *line, int i);
void				check_texture(t_cub *cub, char *line);
void				check_texture_no(t_cub *cub, char *line, int i);
void				check_texture_ea(t_cub *cub, char *line, int i);
void				check_texture_we(t_cub *cub, char *line, int i);
void				check_texture_so(t_cub *cub, char *line, int i);
void				check_texture_sp(t_cub *cub, char *line, int i);
void				tex_path(t_cub *cub, int i, char *line, char **s);
void				get_colors(t_cub *cub, char *line);
void				comma_count(t_cub *cub, char *line, int j, int x);
void				save_color_value(t_cub *cub, char *line, int i, int j);
void				check_valid_col(t_cub *cub, int i, int j);
void				get_rgb(t_cub *cub, char *line, int x);
int					line_is_map(t_cub *cub, char *line);
void				check_valid_map(t_cub *cub);
void				check_available(t_cub *cub, int i, int n, int o);
void				check_lines(t_cub *cub);
void				map_valid_position(t_cub *cub, int i, int j);
void				check_walls(t_cub *cub, int i, int j, char c);
void				check_obj_pos(t_cub *cub, int i, int j);
void				check_walls_next(t_cub *cub, int i, int j, char c);
void				handle_spaces(t_cub *cub, int i, int j);
void				last_check(t_cub *cub, int i, int j);
void				plr_start_position(t_cub *cub);
void				get_walls_img(t_cub *cub);
void				visual_map(t_cub *cub, int i, int j, int x);
void				put_colors(t_cub *cub, int i, int j);
void				start_ray(t_cub *cub, int x);
void				step_sidedist(t_cub *cub);
void				perp_wall_dist(t_cub *cub);
void				draw_walls(t_cub *cub, int x);
void				sprite_handler(t_cub *cub);
void				hit_wall(t_cub *cub);
int					press_the_key(int key, t_cub *cub);
int					release_the_key(int key, t_cub *cub);
int					key_handler(t_cub *cub);
void				moving_forward(t_cub *cub);
void				moving_back(t_cub *cub);
void				move_left(t_cub *cub);
void				move_right(t_cub *cub);
void				turn_left(t_cub *cub);
void				turn_right(t_cub *cub);
void				set_textures(t_cub *cub);
void				draw_sprite(t_cub *cub);
void				set_sprite_param(t_cub *cub, int i, double inv_det);
void				sorting_spr(t_cub *cub, t_sprites *spr, int i, int j);
void				save_screen(t_cub *cub);
void				valid_value(char *line, t_cub *cub);
int					free_exit(t_cub *cub, int type);

#endif
