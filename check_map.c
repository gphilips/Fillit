#include "fillit.h"
#include <stdio.h>

int		ft_check_char(char *buff)
{
	int		i;
	int		point;
	int		sharp;
	int		endline;

	i = 0;
	point = 0;
	sharp = 0;
	endline = 0;
	while (buff[i] && (buff[i] == '.' || buff[i] == '#' || buff[i] == '\n'))
	{
		if (buff[i] == '.')
			point++;
		if (buff[i] == '#')
			sharp++;
		if (buff[i] == '\n')
			endline++;
		i++;
	}
	if (point == 12 && sharp == 4 && endline == 4)
		return (1);
	else
		ft_putendl("Error");
	return (0);
}

int		ft_check_line(char *buff)
{
	int			i;
	int			line;

	i = 0;
	line = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			line++;
		if (line > 4)
			return (0);
		i++;
	}
	return (1);
}

/*
int		ft_check_form(char *buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			if (buff[i] == buff[i + 10] || buff[i] == buff[i + 6]
				|| buff[i] == buff[i + 3] || buff[i] == buff[i + 7]
				|| buff[i] == buff[i + 5] || buff[i] == buff[i + 11])
				return (1);
		}
		i++;
	}
	return (0);
}
*/

int		main(int argc, char **argv)
{
	int		fd;
	int		rd;
	int		checkchar;
	int		checkline;
//	int		checkform;
	char	buff[BUFF_SIZE + 1];

	if (argc != 2)
	{
		ft_putendl_fd("Error: argc", 2);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)))
	{
		if ((rd = read(fd, buff, BUFF_SIZE) > 0))
			ft_putendl(buff);
		if (rd == 0)
		{
			ft_putendl_fd("Error: read 0", 2);
			return (0);
		}
		else if (rd < 0)
		{
			ft_putendl_fd("Error: read -1", 2);
			return (0);
		}
	}
	else
	{
		ft_putendl_fd("Error: open", 2);
		return (0);
	}
	checkchar = ft_check_char(buff);
	checkline = ft_check_line(buff);
//	checkform = ft_check_form(buff);
	printf("Resultat checkchar: %d\n", checkchar);
	printf("Resultat checkline: %d\n", checkline);
//	printf("Resultat checkform: %d\n", checkform);
	close(fd);
	return (0);
}
