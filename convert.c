/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:46:58 by fmuller           #+#    #+#             */
/*   Updated: 2016/12/16 19:01:28 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static size_t	ft_nb_of_col(char *tetri)
{
	size_t	n;
	size_t	k;
	size_t	column;
	size_t	is_column;

	k = 0;
	n = 0;
	column = 0;
	is_column = 0;
	while (k < 4)
	{
		n = k;
		while (n < 14)
		{
			if (ft_isalpha(tetri[n]))
				is_column = 1;
			n = n + 5;
		}
		if (is_column)
			column++;
		is_column = 0;
		k++;
	}
	return (column);
}

static size_t	ft_nb_of_line(char *tetri)
{
	size_t	n;
	size_t	line;
	size_t	is_line;

	n = 0;
	line = 0;
	is_line = 0;
	while (tetri[n])
	{
		while (tetri[n] != '\n')
		{
			if (ft_isalpha(tetri[n]))
				is_line = 1;
			n++;
		}
		if (is_line == 1)
			line++;
		is_line = 0;
		if (tetri[n] == '\n')
			n++;
	}
	return (line);
}

static void		ft_prout(t_point3 *p, char **tab, char ***t, size_t *x)
{
	while (p->x < ft_nb_of_col(tab[p->k]))
	{
		t[p->k][p->y][p->x] = tab[p->k][*x];
		p->x++;
		(*x)++;
	}
}

char			***ft_convert(char **tab, size_t nbtetri)
{
	char		***t;
	size_t		x;
	t_point3	p;

	p.k = 0;
	t = ft_memalloc(sizeof(char**) * (nbtetri + 1));
	while (p.k < nbtetri)
	{
		t[p.k] = ft_memalloc(sizeof(char*) * (ft_nb_of_line(tab[p.k]) + 1));
		p.y = 0;
		x = 0;
		while (p.y < ft_nb_of_line(tab[p.k]))
		{
			t[p.k][p.y] = ft_strnew(sizeof(char) *
							(ft_nb_of_col(tab[p.k]) + 1));
			p.x = 0;
			ft_prout(&p, tab, t, &x);
			while (tab[p.k][x] != '\n')
				x++;
			x++;
			p.y++;
		}
		p.k++;
	}
	return (t);
}
