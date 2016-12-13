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

char	**ft_read_tetris(char *argv)
{
	int			fd;
	int			rd;
	char		buff[BUFF_SIZE + 1];
	char		**tab;
	int			i;

	i = 0;
	tab = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putendl("Cannot open the file, it's might be empty");
		return (NULL);
	}
	if ((rd = read(fd, buff, BUFF_SIZE)) > 0)
		buff[rd] = '\0';
	else if (rd == 0)
	{
		ft_putendl("Error: The file is Empty");
		return (NULL);
	}
	else
	{
		ft_putendl("Error: Cannot read the file");
		return (NULL);
	}
	tab = ft_buff_to_tab(tab, buff);
	return (tab);
}

