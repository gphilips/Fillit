# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gphilips <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 19:14:28 by gphilips          #+#    #+#              #
#    Updated: 2016/11/21 19:14:38 by gphilips         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = check_tetris.c	\
		count_tetris.c	\
		get_tetris.c	\
		read.c			\
		alphabet.c		\
		map.c			\
		main.c			\

LIB = libft.a

OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(FILES) $(LIB) 
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
