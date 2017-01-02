/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:38:35 by fmuller           #+#    #+#             */
/*   Updated: 2017/01/02 16:33:43 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE (20 * 26) + (1 * 25)

typedef struct	s_point
{
	size_t	x;
	size_t	y;
}				t_point;

typedef struct	s_point3
{
	size_t	k;
	size_t	x;
	size_t	y;
}				t_point3;

int				ft_error(int argc, char **argv, char ***tab);

char			**ft_read_tetris(char *argv);

char			*ft_alphabet(char *tab, int id);
void			ft_replacetab(char **tab, int nbtetris);

char			***ft_convert(char **tab, size_t nbtetri);

size_t			ft_estimate_square_size(size_t	nbtetri);
char			**ft_create_square(size_t square_size);
void			ft_free_square(char **square);

int				ft_test(char ***tab, int i, char **square);
void			ft_free_all(char **tab, char **square, char ***t);
#endif
