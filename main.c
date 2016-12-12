#include "fillit.h"

int		main(int argc, char **argv)
{
	char		**tab;
	t_tetris	*list_tet;

	tab = NULL;
	list_tet = NULL;
	if (argc != 2)
	{
		ft_putendl("Error\n Usage: ./fillit file");
		return (0);
	}
	if (!(tab = ft_read_tetris(argv[1])))
		return (0);
	if ((ft_check_all(tab) == 0))
	{
		ft_putendl("Error: File not valid");
		return (0);
	}
	list_tet = ft_tab_to_lst(tab);
	ft_print_tetris(list_tet);
	return (1);
}
