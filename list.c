/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:34:21 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/06 19:34:22 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*ft_lst_new_tetris(char **tab, int id)
{
	t_tetris	*new_tetris;

	new_tetris = NULL;
	if (!(new_tetris = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	new_tetris->tetris = ft_alphabet(tab, id);
	new_tetris->x = 0;
	new_tetris->y = 0;
	new_tetris->next = NULL;
	return (new_tetris);
}

t_tetris	*ft_tab_to_lst(char **tab)
{
	t_tetris	*new_tetris;
	t_tetris	*first;
	int			nb_tetris;
	int			i;
	
	i = 0;
	nb_tetris = 0;
	new_tetris = NULL;
	first = NULL;
	new_tetris = ft_lst_new_tetris(&tab[0], 0);
	first = new_tetris;
	i = 1;
	while (tab[nb_tetris])
		nb_tetris++;
	while (i < nb_tetris)
	{
		first->next = ft_lst_new_tetris(&tab[i], i);
		i++;
		first = first->next;
	}
	return (new_tetris);
}

/* ____FONCTION TEST____ */
void	ft_print_tetris(t_tetris *list)
{
	t_tetris	*first;
	int			i;

	first = NULL;
	first = list;
	i = 1;
	while (first)
	{
		printf("Maillon %d \n", i);
		printf("%s", *first->tetris);
		first = first->next;
		i++;
	}
}
