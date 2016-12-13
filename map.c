#include "fillit.h"

char	**ft_create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	if (!(map = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i < size)
	{
		while (j < size)
		{
			if (!(map[j] = ft_strnew(size + 1)))
				return (NULL);
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		j = 0;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_print_map(char **map)
{
	int		i;
	
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
