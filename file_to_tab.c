/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:34:04 by fmuller           #+#    #+#             */
/*   Updated: 2016/12/16 18:16:52 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_count_tetris(char *buff)
{
	int		i;
	int		count;

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

static void		ft_prout(char **tab, char *buff, t_point3 *p)
{
	while (p->x < 20)
	{
		tab[p->y][p->x] = buff[p->k];
		p->x++;
		p->k++;
	}
	tab[p->y][p->x] = '\0';
	p->x = 0;
}

static char		**ft_buff_to_tab(char **tab, char *buff)
{
	t_point3	p;
	size_t		nb_tetris;

	p.y = 0;
	p.x = 0;
	p.k = 0;
	nb_tetris = ft_count_tetris(buff);
	if (!(tab = (char**)ft_memalloc(sizeof(char *) *
		(ft_strlen(buff) / 20 + 1))) || nb_tetris == 0)
		return (NULL);
	while (p.y < nb_tetris)
	{
		if (!(tab[p.y] = (char*)ft_memalloc(sizeof(char) * (20 + 1))))
			return (NULL);
		ft_prout(tab, buff, &p);
		if (buff[p.k] != '\n' && buff[p.k] != '\0')
			return (NULL);
		if (buff[p.k] == '\n')
			p.k++;
		p.y++;
	}
	if (buff[p.k] != '\0')
		return (NULL);
	return (tab);
}

char			**ft_read_tetris(char *argv)
{
	int			fd;
	int			rd;
	char		buff[BUFF_SIZE + 1];
	char		**tab;

	tab = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if ((rd = read(fd, buff, BUFF_SIZE)) > 0)
		buff[rd] = '\0';
	else
		return (NULL);
	if (read(fd, buff, BUFF_SIZE) > 0)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	tab = ft_buff_to_tab(tab, buff);
	return (tab);
}
