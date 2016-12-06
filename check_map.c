/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:34:10 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/06 19:34:12 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_char(char *buff)
{
	int		i;
	int		point;
	int		sharp;
	int		endline;

	i = 0;
	point = 0;
	sharp = 0;
	endline = 0;
	while (buff[i] && (buff[i] == '.' || buff[i] == '#' || buff[i] == '\n'))
	{
		if (buff[i] == '.')
			point++;
		if (buff[i] == '#')
			sharp++;
		if (buff[i] == '\n')
			endline++;
		i++;
	}
	if (point == 12 && sharp == 4 && endline == 4)
		return (1);
	else
		ft_putendl("Error");
	return (0);
}

int		ft_check_line(char *buff)
{
	int			i;
	int			line;

	i = 0;
	line = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			line++;
		i++;
	}
	if (line != 4)
		return (0);
	else
		return (1);
}
