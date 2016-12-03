/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:22:49 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/03 19:10:30 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

#define BUFF_SIZE 22

typedef struct			s_tetris
{
	char				**tetris;
	char				letter;
	int					x;
	int					y;
	struct s_tetris		*next;
}						t_tetris;

int					ft_check_char(char *buffer);
int					ft_check_line(char *buffer);
int					ft_check_form(char *buffer);
char					ft_nb_tetris(char *buff);

#endif
