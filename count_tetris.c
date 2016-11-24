#include "fillit.h"

char	ft_nb_tetris(char *buff)
{
	int		i;
	int 	count;
		
	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '\n' && buff[i + 1] == '\n')
			count++;
		i++;
	}
	return (count);
}
