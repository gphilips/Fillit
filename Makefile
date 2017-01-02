# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 16:01:10 by fmuller           #+#    #+#              #
#    Updated: 2017/01/02 16:37:55 by gphilips         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS =
LIB = ft
LIBDIR = libft
SRC = main.c file_to_tab.c check.c modif_tab.c convert.c square.c \
	  join_tetri.c free_all.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@$(CC) -L $(LIBDIR) -l $(LIB) $(LDFLAGS) -o $@ $(OBJ)
	@echo "fillit created"

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBDIR)
	@echo "Erasing .o files."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBDIR)
	@echo "Erasing $(NAME)."

re: fclean all
