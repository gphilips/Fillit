/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:51:12 by fmuller           #+#    #+#             */
/*   Updated: 2017/01/02 16:26:04 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

size_t	ft_estimate_square_size(size_t nbtetri)
{
	size_t	square_size;

	square_size = 1;
	while ((square_size * square_size) < (nbtetri * 4))
		square_size++;
	return (square_size);
}

char	**ft_create_square(size_t square_size)
{
	char	**square;
	size_t	n;

	square = ft_memalloc(sizeof(char *) * (square_size + 1));
	n = 0;
	while (n < square_size)
	{
		square[n] = ft_memalloc(sizeof(char) * (square_size + 1));
		ft_memset(square[n], '.', square_size);
		n++;
	}
	return (square);
}
