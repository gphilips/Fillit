#include "fillit.h"
#include <stdio.h>

int		ft_check_char(char *buff)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == '.' || buff[i] == '#')
			count++;
		else
		{
			//ft_putendl_fd("A char is not valid", 2);
			return (0);
		}
		if (count == 4 && buff[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_line(char *buff)
{
	int			i;
	int			line_valid;

	i = 0;
	line_valid = 0;
	while (buff[i])
	{
		if (buff[i] == '\n' && ft_check_char(buff) == 1)
			line_valid++;
		if (line_valid == 4)
		{
			if (buff[i + 1] == '\n' && (buff[i + 1] == '.' || buff[i + 1] == '#'))
			{
				line_valid = 0;
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

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

int		main(int argc, char **argv)
{
	int		fd;
	int		rd;
	int		checkchar;
	int		checkline;
	int		checkform;
	char	buff[BUFF_SIZE + 1];

	if (argc != 2)
	{
		ft_putendl_fd("Error: argc", 2);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)))
	{
		if ((rd = read(fd, buff, BUFF_SIZE) > 0))
			ft_putendl_fd(buff, 1);
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
	checkform = ft_check_form(buff);
	printf("Resultat checkchar: %d\n", checkchar);
	printf("Resultat checkline: %d\n", checkline);
	printf("Resultat checkform: %d\n", checkform);
	close(fd);
	return (0);
}
