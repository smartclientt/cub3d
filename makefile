# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 02:20:16 by shbi              #+#    #+#              #
#    Updated: 2023/01/11 06:03:57 by shbi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	cub3d
SRCS	=	cub3d.c \
			dda_algo.c libft_functions.c libft_functions_.c
			
OBJS	=	$(SRCS:.c=.o)
HEADR	=	cub3d.h
CC		=	cc
CFLAG	=	-Wall -Werror -Wextra
RM		=	rm -rf

all			:	$(NAME)
				$(RM) $(OBJS)
$(NAME)		:	$(OBJS)
				$(CC) $(CFLAG) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
%.o			:	%.c $(HEADR)
				$(CC) $(CFLAG) -Imlx -c $< -o $@
clean		:
				$(RM) $(OBJS)
fclean		:	clean
				$(RM) $(NAME)
re			:	fclean all 