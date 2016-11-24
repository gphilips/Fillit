#include "fillit.h"

char		ft_read_map(char *argv)
{
	int		fd;
	int		rd;
	char	buff;
	int		nb_tetris;
	char	**tab;

	if (fd = open(argv, O_RDONLY) == -1)
		return (NULL);
	while (rd = read(fd, buff, BUFF_SIZE) > 0)
		buff[rd] = '\0';
	nb_tetris = ft_nb_tetris(buff);
	
	return ();
}
