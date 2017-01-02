/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:23:55 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/02 16:39:47 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void		ft_free_tab(char **tab)
{
	int		y;

	y = 0;
	while (tab[y])
	{
		free(tab[y]);
		tab[y] = NULL;
		y++;
	}
	free(tab);
	tab = NULL;
}

void			ft_free_square(char **square)
{
	size_t	n;

	n = 0;
	while (square[n])
	{
		ft_memdel((void **)&square[n]);
		n++;
	}
	ft_memdel((void **)&square[n]);
	ft_memdel((void **)&square);
}

static void		ft_free_t(char ***t)
{
	int		k;
	int		y;

	k = 0;
	y = 0;
	while (t[k])
	{
		while (t[k][y])
		{
			free(t[k][y]);
			t[k][y] = NULL;
			y++;
		}
		free(t[k]);
		t[k] = NULL;
		k++;
		y = 0;
	}
	free(t);
	t = NULL;
}

void			ft_free_all(char **tab, char **square, char ***t)
{
	ft_free_tab(tab);
	ft_free_square(square);
	ft_free_t(t);
}
