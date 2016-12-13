/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:48:35 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/13 15:43:51 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		**tab;
//	t_tetris	*list_tet;
	char		**map;
	int			i;

	i = 0;
	tab = NULL;
//	list_tet = NULL;
	map = NULL;
	if (argc != 2)
	{
		ft_putendl("Error\n Usage: ./fillit file");
		return (0);
	}
	if (!(tab = ft_read_tetris(argv[1])))
		return (0);
	printf("Checkall: %d\n", ft_check_all(tab));
	if ((ft_check_all(tab) == 0))
	{
		ft_putendl("Error: File not valid");
		return (0);
	}
	while (tab[i])
	{
		ft_alphabet(tab[i], i);
		i++;
	}
	ft_putendl("_____TAB______");
	int			j = 0;
	while (tab[j])
	{
		printf("Tab %d:\n%s", j, tab[j]);
		j++;
	}
//	list_tet = ft_tab_to_lst(tab);
//	ft_print_tetris(list_tet);
	ft_putendl("_____MAP______");
	ft_print_map(ft_create_map(8));
	return (1);
}
