#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>i
# include <fcntl.h>

#define BUFF_SIZE 20

typedef struct			s_tetris
{
	char				**tetris;
	char				letter;
	int					x;
	int					y;
	struct s_tetris		*next;
}						t_tetris;

char					ft_read_map(char *argv);
char					ft_nb_tetris(char *buff);
