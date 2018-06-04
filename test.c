#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 32



static	int	buflen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (++i);
}

static	int	get_next_line(int file, char **line)
{
	static	char	buf[BUFF_SIZE];
	static	int		i;
	static	int		run;
	int				count;
	int				index;

	if (run++ == 0)
		i = BUFF_SIZE;
	if (i == BUFF_SIZE)
	{
		 i = 0;
		 count = read(file, buf, BUFF_SIZE);
	}
	if (count == -1)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * buflen(buf))))
		return (0);
	while (buf[i] != '\n' && buf[i] != '\0' && i != BUFF_SIZE)
	{
		line[index] = buf[i];
		printf("%c", line[index]);
		i++;
		line[index] = '\0';
	}
	if (buf[i] == '\n' && i < BUFF_SIZE)
	{
		i++;
		printf("\n");
		return (count);
	}
	if (i == BUFF_SIZE)
		return (count);
	return (0);
}

int			main()
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
		printf("%s", hold);
	}
	return (0);
}
