#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int get_next_line(const int fd, char **line);

int	main(void)
{
	int		file1;
	int		file2;
	int		file3;
	int		file4;
	char	*hold1;
	char	*hold2;
	char	*hold3;
	char	*hold4;
	int j;
	int i;

	j = 1;
	i = 1;
	hold1 = NULL;
	hold2 = NULL;
	hold3 = NULL;
	hold4 = NULL;
	file1 = open("test1.txt", O_RDONLY);
	file2 = open("test2.txt", O_RDONLY);
	file3 = open("test3.txt", O_RDONLY);
	file4 = open("test4.txt", O_RDONLY);
	

	while (j == 1)
	{
		j = get_next_line(file1,&hold1);
		printf("%d======%s======\n",i++ , hold1);
		j = get_next_line(file2,&hold2);
		printf("%d======%s======\n",i++ , hold2);
		j = get_next_line(file3,&hold3);
		printf("%d======%s======\n",i++ , hold3);
		j = get_next_line(file4,&hold4);
		printf("%d======%s======\n",i++ , hold4);
		free(hold1);
		free(hold2);
		free(hold3);
		free(hold4);
	}
	close(file1);
	close(file2);
	close(file3);
	close(file4);
	return (0);
}
