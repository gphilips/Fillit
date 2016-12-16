/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:55:48 by fmuller           #+#    #+#             */
/*   Updated: 2016/12/16 19:33:59 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**Copie un tetriminos dans square au coordonne donner
*/

static void	ft_copy(char **tetri, char **square, t_point p)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tetri[y])
	{
		x = 0;
		while (tetri[y][x])
		{
			if (ft_isalpha(tetri[y][x]))
				square[p.y + y][p.x + x] = tetri[y][x];
			x++;
		}
		y++;
	}
}

/*
**Enleve un tetriminos de square au coordonne donner
*/

static void	ft_uncopy(char **tetri, char **square, t_point p)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tetri[y])
	{
		x = 0;
		while (tetri[y][x])
		{
			if (ft_isalpha(tetri[y][x]))
				square[p.y + y][p.x + x] = '.';
			x++;
		}
		y++;
	}
}

/*
**Test si il est possible de copier un tetriminos dans square au coordone donne
*/

static int	ft_test_pos(char **tetri, char **square, t_point p)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tetri[y])
	{
		x = 0;
		while (tetri[y][x])
		{
			if (p.y + y == ft_strlen(square[0]) ||
				(ft_isalpha(tetri[y][x]) &&
					ft_isalpha(square[p.y + y][p.x + x])) ||
				square[p.y + y][p.x + x] == '\0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
**Avance d'une case dans le tableau (c'est surtout pour ganger de la place)
*/

static void	ft_cordonate_pp(t_point *p, size_t square_size)
{
	if (p->x == square_size - 1)
	{
		p->y++;
		p->x = 0;
	}
	else
		p->x++;
}

int			ft_test(char ***tab, int i, char **square)
{
	t_point	p;
	size_t	square_size;

	p.y = 0;
	p.x = 0;
	square_size = ft_strlen(square[0]);
	while (!(p.x == square_size - 1 && p.y == square_size - 1))
	{
		while (!ft_test_pos(tab[i], square, p) &&
			!(p.x == square_size - 1 && p.y == square_size - 1))
			ft_cordonate_pp(&p, square_size);
		if (p.x == square_size - 1 && p.y == square_size - 1)
			return (0);
		ft_copy(tab[i], square, p);
		if (tab[i + 1] == 0 || ft_test(tab, i + 1, square))
			return (1);
		else
		{
			ft_uncopy(tab[i], square, p);
			ft_cordonate_pp(&p, square_size);
		}
	}
	return (0);
}
