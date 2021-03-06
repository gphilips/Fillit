/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:32:46 by fmuller           #+#    #+#             */
/*   Updated: 2016/12/16 18:14:03 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_char(char *buff)
{
	int		i;
	int		hash;
	int		point;
	int		nextline;

	i = -1;
	hash = 0;
	point = 0;
	nextline = 0;
	while (buff[++i])
	{
		if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
			return (0);
		if (buff[i] == '#')
			hash++;
		if (buff[i] == '.')
			point++;
		if (buff[i] == '\n')
			nextline++;
	}
	if (hash == 4 && point == 12 && nextline == 4)
		return (1);
	return (0);
}

static int		ft_check_line(char *buff)
{
	int			i;
	int			count;
	int			line;

	i = 0;
	count = 0;
	line = 0;
	while (buff[i])
	{
		if (buff[i] == '#' || buff[i] == '.')
			count++;
		if (count > 4)
			return (0);
		if (buff[i] == '\n' && count == 4)
		{
			count = 0;
			line++;
		}
		if (line > 4)
			return (0);
		i++;
	}
	return (1);
}

static int		ft_checkform(char *tetris)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (tetris[i])
	{
		if (tetris[i] == '#')
		{
			if (tetris[i + 1] == '#')
				count += 1;
			if (tetris[i + 5] == '#')
				count += 1;
			if (count == 4)
				return (1);
		}
		i++;
	}
	return (0);
}

static int		ft_check_all(char **tab)
{
	int		nb_tetris;
	int		i;

	nb_tetris = 0;
	i = 0;
	while (tab[nb_tetris])
		nb_tetris++;
	while (i < nb_tetris)
	{
		if ((ft_check_char(tab[i]) == 0) || (ft_check_line(tab[i]) == 0)
				|| (ft_checkform(tab[i]) == 0))
			return (0);
		i++;
	}
	return (1);
}

int				ft_error(int argc, char **argv, char ***tab)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (0);
	}
	if (!(*tab = ft_read_tetris(argv[1])))
	{
		ft_putendl("error");
		return (0);
	}
	if (ft_check_all(*tab) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}
