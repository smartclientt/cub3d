# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 02:20:16 by shbi              #+#    #+#              #
#    Updated: 2023/02/01 22:46:43 by shbi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= 	cub3d
NAME_BONUS			=	cub3d_bonus
SRCS				=	cub3d.c 															\
						dda_algo.c dda_algo_.c dda_algo__.c make_moves.c					\
						GNL/get_next_line.c GNL/get_next_line_utils.c 						\
						parsing/utils.c parsing/utils1.c parsing/utils2.c parsing/utils3.c	\
						parsing/map_checker.c parsing/check_assets.c  						\
						parsing/read_map.c parsing/check_playermap.c 						\
						parsing/init_dir_vec.c mlx/_mlx.c mlx/mlx1.c

OBJS				=	$(SRCS:.c=.o)
HEADR				=	cub3d.h
PATH_LIBFT 			=	libft/
LIBFT				=	libft/libft.a
CC					=	cc
CFLAG				=	-Wall -Werror -Wextra -Ofast
RM					=	rm -rf

all					:	$(NAME)
bonus				:	$(NAME_BONUS)
$(LIBFT)			:
						@make -C $(PATH_LIBFT)
$(NAME)				:	$(OBJS) $(HEADR) $(LIBFT)
						$(CC) $(CFLAG) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT)
$(NAME_BONUS)		:	$(OBJS) $(HEADR) $(LIBFT)
						$(CC) $(CFLAG) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(OBJS) $(LIBFT)
%.o					:	%.c $(HEADR) 
						$(CC) $(CFLAG) -Imlx -c $< -o $@
clean				:
						$(RM) $(OBJS)
						@make clean -C $(PATH_LIBFT)
fclean				:	clean
						@make fclean -C $(PATH_LIBFT)
						$(RM) $(NAME)
						$(RM) $(NAME_BONUS)
re					:	fclean all
re_bonus			:	fclean bonus
