/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:03:38 by fmuller           #+#    #+#             */
/*   Updated: 2017/01/02 16:37:04 by gphilips         ###   ########.fr       */
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
	square_size = ft_estimate_square_size(j);
	square = ft_create_square(square_size);
	while (!ft_test(t, 0, square))
	{
		ft_free_square(square);
		square_size++;
		square = ft_create_square(square_size);
	}
	ft_put_tabs(square);
	ft_free_all(tab, square, t);
	return (1);
}
