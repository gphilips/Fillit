/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:34:15 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/06 19:34:16 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:22:49 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/06 18:14:47 by gphilips         ###   ########.fr       */
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

# include <stdio.h>

#define BUFF_SIZE 4096

typedef struct		s_tetris
{
	char			**tetris;
	char			letter;
	struct s_tetris	*prev;
	struct s_tetris	*next;
}					t_tetris;
int					ft_check_char(char *buff);
int					ft_check_line(char *buff);
int					ft_read_tetris(char *argv);
char				ft_nb_tetris(char *buff);

#endif
