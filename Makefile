# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scass <scass@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 01:17:19 by scass             #+#    #+#              #
#    Updated: 2021/04/25 03:49:04 by scass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D
SRCS =		./srcs/start_cub.c ./srcs/errors.c ./srcs/check_textures.c \
			./srcs/parser_color.c ./srcs/parsing_map.c	./srcs/last_check_map.c \
			./srcs/get_configuration.c ./srcs/get_image.c ./srcs/key_handler.c \
			./srcs/key_handler_turn.c ./srcs/check_valid_map.c ./srcs/visual_map.c \
			./srcs/draw_walls.c ./srcs/draw_sprite.c ./srcs/save_screen.c \
			./srcs/sorting_spr.c ./srcs/main.c ./srcs/get_resolution.c ./srcs/valid_value.c \
			./srcs/save_and_check_color.c
LIBFT =		libft
MLX =		./minilibx-linux
LIBS = 		./libft/libft.a ./minilibx-linux/libmlx.a	
OBJS =		$(SRCS:.c=.o)
HEADER = 	./srcs/cub.h
%.o:		%.c $(HEADER)
			$(CC)   -c $< -o $(<:.c=.o) $(FLAGS)


CC =		gcc
CFLAGS =	-Wall -Wextra -Werror 
FLAGS =		-lX11 -lXext -lm -g
RM =		rm -f
all :		$(NAME) 

$(NAME) :	$(OBJS) $(LIBFT)
			$(MAKE) -C $(LIBFT) all
			$(MAKE) -C $(MLX) all
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADER) $(LIBS) $(FLAGS) 
			@echo "cub3D is ready"

$(LIBFT) :  libft/*.c libft/*.h
			$(MAKE) -C $(LIBFT) all
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADER) $(LIBS) $(FLAGS)


clean :		
			$(MAKE) -C $(LIBFT) clean
			$(MAKE) -C $(MLX) clean
			$(RM) $(OBJS) ./save.bmp

fclean 	:	clean
			$(MAKE) -C $(LIBFT) fclean
			$(RM) $(NAME)

re :		fclean all

run :		
			./cub3D map/base/map.cub

save :		
			./cub3D map/base/map.cub --save

norm:
			norminette srcs/*.c srcs/cub.h libft/*.c libft/libft.h

.PHONY :	all clean fclean re run save norm
