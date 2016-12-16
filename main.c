/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:03:38 by fmuller           #+#    #+#             */
/*   Updated: 2016/12/16 19:44:38 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		**tab;
	char		***t;
	char		**square;
	size_t		square_size;
	int			j;

	j = -1;
	tab = NULL;
	if (!ft_error(argc, argv, &tab))
		return (0);
	while (tab[++j])
		ft_alphabet(tab[j], j);
	ft_replacetab(tab, (j - 1));
	t = ft_convert(tab, j);
	ft_memdel((void **)&*tab);
	square_size = ft_estimate_square_size(j);
	square = ft_recreate_square(t, square_size);
	ft_put_tabs(square);
	ft_memdel((void **)&*t);
	return (1);
}
