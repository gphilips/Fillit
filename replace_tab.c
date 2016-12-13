/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:23:47 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/13 17:23:49 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_replace(char *tab, int *pos)
{
	int	n;

	while (pos[0] > 4 && pos[1] > 4 && pos[2] > 4 && pos[3] > 4)
	{
		n = 0;
		while (n < 4)
		{
			tab[pos[n] - 5] = tab[pos[n]];
			tab[pos[n]] = '.';
			pos[n] -= 5;
			n++;
		}
	}
	while (pos[0] != 0 && tab[pos[1] - 1] != '\n' &&
			tab[pos[2] - 1] != '\n' && tab[pos[3] - 1] != '\n')
	{
		n = 0;
		while (n < 4)
		{
			tab[pos[n] - 1] = tab[pos[n]];
			tab[pos[n]] = '.';
			pos[n] -= 1;
			n++;
		}
	}
}

void		ft_replace_tab(char **tab, int nbtetris)
{
	int	i;
	int n;
	int	position[4];

	while (nbtetris >= 0)
	{
		i = 0;
		n = 0;
		while (n < 4)
		{
			if (ft_isalpha(tab[nbtetris][i]))
			{
				position[n] = i;
				n++;
			}
			i++;
		}
		ft_replace(tab[nbtetris], position);
		nbtetris--;
	}
}
