#include "fillit.h"

int		ft_check_line(char *buff)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			j++;
		if (j == 4)
		{
			if (buff[i + 1] == '\n' && buff[i + 1] != '\0')
			{
				i++;
				j = 0;
			}
			else if (buff[i + 1] != '\n' && buff[i + 1] != '\0')
			return (0);
		}
		i++;
	}
	return (1);
}
