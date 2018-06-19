#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int get_next_line(const int fd, char **line);

int	main(int i, char **c)
{
	int		file[--i];
	char	*hold1;
	int		j;
	int		p;

	j = 0;
	p = 1;
	hold1 = NULL;
	printf("%d", i);
	while (j < i)
	{
		file[j] = open(c[1+j], O_RDONLY);
		j++;
	}
	j = 0;
		while (p == 1)
		{
			p = get_next_line(file[j++],&hold1);
			printf("======%s======\n", hold1);
			free(hold1);
			if (p == 0 && j < i)
				p = 1;
			if (j == i)
				j = 0;
		}
	j = 0;
	while (close(file[j++]));
	return (0);
}
