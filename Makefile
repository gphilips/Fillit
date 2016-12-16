# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 16:01:10 by fmuller           #+#    #+#              #
#    Updated: 2016/12/16 19:46:24 by gphilips         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS =
LIB = ft
LIBDIR = libft
SRC = main.c file_to_tab.c check.c modif_tab.c convert.c square.c \
	  join_tetri.c recreate_square.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LIBDIR) && make 
	@$(CC) -L $(LIBDIR) -l $(LIB) $(LDFLAGS) -o $@ $(OBJ)
	@echo "fillit created"

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ)
	@cd $(LIBDIR) && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd $(LIBDIR) && make fclean

re: fclean all
	@cd $(LIBDIR) && make re
