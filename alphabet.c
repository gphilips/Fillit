#include "fillit.h"

char	*ft_alphabet(char *tab, int id)
{
	int			i;
	int			letter;

	i = 0;
	letter = 'A';
	while (tab[i] && letter <= 'Z')
	{
		if (tab[i] == '#')
			tab[i] = letter + id;
		i++;
	}
	return (tab);
}
