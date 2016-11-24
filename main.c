#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd("error", 2);
	rd = ft_read_map(argv[1]);
	if (rd == 0)
		ft_putstr_fd("error", 2);
	return (0);
}
