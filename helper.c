#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int get_next_line(int fd, char **line);

int				main(int i, char **c)
{
	int		file1;
	int		file2;
	int		file3;
	int		file4 = 19;;
	char	*hold1;
	char	*hold2;
	char	*hold3;
	char	*hold4;
	int j;

	j = 1;
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
		printf("======%s======\n", hold1);
		j = get_next_line(file2,&hold2);
		printf("======%s======\n", hold2);
		j = get_next_line(file4,&hold3);
		printf("======%s======\n", hold3);
		j = get_next_line(file3,&hold4);
		printf("======%s======\n", hold4);
}
	close(file1);
	close(file2);
	close(file3);
	close(file4);
	return (0);
}
