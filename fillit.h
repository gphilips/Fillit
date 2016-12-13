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
# include "libft.h"

# include <stdio.h>

#define BUFF_SIZE 4096
/*
typedef struct		s_tetris
{
	char			**tetris;
	int				x;
	int				y;
	struct s_tetris	*next;
}					t_tetris;*/
int					ft_check_all(char **tab);
char				**ft_read_tetris(char *argv);
char				**ft_buff_to_tab(char **tab, char *buff);
int					ft_count_tetris(char *buff);
//t_tetris			*ft_lst_new_tetris(char **tab, int id);
//t_tetris			*ft_tab_to_lst(char **tab);
char				*ft_alphabet(char *tab, int id);
//void				ft_print_tetris(t_tetris *first);
char				**ft_create_map(int size);
void				ft_print_map(char **map);
#endif
