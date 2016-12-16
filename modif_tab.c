/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:43:49 by fmuller           #+#    #+#             */
/*   Updated: 2016/12/16 19:26:56 by gphilips         ###   ########.fr       */
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

void		ft_replacetab(char **tab, int nbtetris)
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

char		*ft_alphabet(char *tab, int id)
{
	int			i;
	int			letter;

	i = 0;
	letter = 'A';
	while (tab[i] && letter <= 'Z')
	{
		if (tab[i] == '#')
			tab[i] = letter + id;
		i++;
	}
	return (tab);
}
