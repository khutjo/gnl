#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 32
/*
static	char	reader(int fd)
{
	char	*swap1;
	char	*swap2;

	read(fd, */
	

static	int	read_line(int const fd, char **line)
{
	int				i;
	static	int		index;
	static	int		place;
	static	int		startrun;
	static	char	buf[1 + BUFF_SIZE];

	i = 0;
	if (startrun == 0)
	{
		place = 0;
		startrun = read(fd, buf, BUFF_SIZE);
		index = startrun;
	}
	if (!((*line) = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	while (startrun > 0 && buf[place] != '\n')
	{
		(*line)[i] = buf[place];
		i++;
		startrun--;
		place++;
	}
	if (buf[place] == '\n' && startrun > 0)
	{
		place++;
		startrun--;
		return (startrun);
	}
	if (startrun == 0 && index == BUFF_SIZE)
	{
		return (1);
	}
	return (0);
}

int get_next_line(int const fd, char **line)
{
	char
	return (re
}

int	main()
{
	int file;
	int i = 1;
	char *hold;

	hold = NULL;
	file = open("test.txt", O_RDONLY);
	if (file == -1)
	{
		printf("fail");
		return (0);
	}
	while (i)
	{
		i = get_next_line(file, &hold);
		printf("%s ======== out \n", hold);
	}
	return (0);
}
