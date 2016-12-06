/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:34:05 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/06 19:34:07 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_tetris(char *argv)
{
	int		fd;
	int		rd;
	char	buff[BUFF_SIZE + 1];

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putendl("Cannot open the file");
		return (0);
	}
	rd = read(fd, buff, BUFF_SIZE);
	if (rd > 0)
		buff[rd] = '\0';
	else if (rd == 0)
	{
		ft_putendl("The file is Empty");
		return (0);
	}
	else
	{
		ft_putendl("Cannot read the file");
		return (0);
	}
	return (1);
}

