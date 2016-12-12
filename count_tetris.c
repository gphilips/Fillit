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
