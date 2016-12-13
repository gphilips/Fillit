/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:49:13 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/13 14:49:14 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetris(char *buff)
{
	int		i;
	int 	count;
		
	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '\n' && (buff[i + 1] == '\n' || buff[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}
