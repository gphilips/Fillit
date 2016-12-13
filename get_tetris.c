/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:49:21 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/13 14:49:23 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_buff_to_tab(char **tab, char *buff)
{
	int		i;
	int		j;
	int		k;
	int		nb_tetris;

	i = 0;
	j = 0;
	k = 0;
	nb_tetris = 0;
	nb_tetris = ft_count_tetris(buff);
	if (!(tab = (char**)malloc(sizeof(char*) * nb_tetris + 1)))
		return (NULL);
	while (i < nb_tetris)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * 20 + 1)))
			return (NULL);
		while (j < 20)
		{
			tab[i][j] = buff[k];
			j++;
			k++;
		}
		tab[i][j] = '\0';
		j = 0;
		if (buff[k] != '\n' && buff[k] != '\0')
		{
			ft_putendl("Error: File not valid");
			return (NULL);
		}
		k++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
