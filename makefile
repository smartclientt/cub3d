# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 02:20:16 by shbi              #+#    #+#              #
#    Updated: 2023/02/01 17:31:32 by shbi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	cub3d
SRCS		=	cub3d.c \
			dda_algo.c dda_algo_.c dda_algo__.c make_moves.c					\
			GNL/get_next_line.c GNL/get_next_line_utils.c 						\
			parsing/utils.c parsing/utils1.c parsing/utils2.c parsing/utils3.c	\
			parsing/map_checker.c parsing/check_assets.c  						\
			parsing/read_map.c parsing/check_playermap.c 						\
			parsing/init_dir_vec.c

OBJS		=	$(SRCS:.c=.o)
HEADR		=	cub3d.h
PATH_LIBFT 	=	libft/
LIBFT		=	libft/libft.a
CC			=	cc
CFLAG		=	-Wall -Werror -Wextra
RM			=	rm -rf

all			:	$(NAME)
				$(RM) $(OBJS)
$(LIBFT)	:
				@make -C $(PATH_LIBFT)
$(NAME)		:	$(OBJS) $(HEADR) $(LIBFT)
				$(CC) $(CFLAG) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT)
%.o			:	%.c $(HEADR) 
				$(CC) $(CFLAG) -Imlx -c $< -o $@
clean		:
				$(RM) $(OBJS)
				@make clean -C $(PATH_LIBFT)
fclean		:	clean
				@make fclean -C $(PATH_LIBFT)
				$(RM) $(NAME)
re			:	fclean all