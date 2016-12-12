#include "fillit.h"

char	**ft_alphabet(char **tab, int id)
{
	int			i;
	int			j;
	int			letter;

	i = 0;
	j = 0;
	letter = 'A';
	while (tab[i][j] && letter <= 'Z')
	{
		if (tab[i][j] == '#')
			tab[i][j] = letter + id;
		j++;
	}
	return (tab);
}
