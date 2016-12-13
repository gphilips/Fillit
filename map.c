/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:50:12 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/13 18:53:39 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(int size)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = ft_strnew(size + 1)))
			return (NULL);
		ft_memset(map[i], '.', size);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_print_map(char **map)
{
	int		i;
	
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
