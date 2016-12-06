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

#include "fillit"

t_tetris	ft_get_tetris(t_tetris *list, t_tetris *new, char **map, int id)
{
	if (!(new = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	if (first == NULL)
	{
		new->tetris = ft_strdup(tetris);
		new->letter = 'A' + id;
		new->prev = NULL;
		first = first->next;
	}
	return (new_tetris);
}

/*	
t_tetris 	ft_print_tetris(t_tetris *first)
{
	int		i;

	i = 0;
	while (first)
	{
		printf("Tetriminos: %d \n", i);
		printf("Tetriminos letter: %s \n", letter);
		printf("%s", first->map);
		i++;
		first = first->next;
	}*/
}
