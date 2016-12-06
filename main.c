#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Error\n Usage: ./fillit file");
		return (0);
	}
	if ((ft_read_tetris(argv[1]) == 0))
		return (0);
	return (0);
}
