/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:46:48 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/16 19:46:50 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_recreate_square(char ***t, size_t square_size)
{
	char	**square;

	square = NULL;
	square = ft_create_square(square_size);
	while (!ft_test(t, 0, square))
	{
		ft_free_square(square);
		square_size++;
		square = ft_create_square(square_size);
	}
	return (square);
}
