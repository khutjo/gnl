/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:58:48 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/08 11:50:31 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 1

static	char	*str_line(char *buf, int size, int start)
{
	int		i;
	char	*rtn_str;

	i = 0;
	rtn_str = NULL;
	if ((rtn_str = (char *)malloc(sizeof(char) * (1 + size))))
	{
		while (i < size)
			rtn_str[i++] = buf[start++];
		rtn_str[i] = '\0';
	}
	return (rtn_str);
}

static	char	*count(char *buf, int place, int *run, int *index)
{
	static	int	i;
	int			size;
	int			hold;

	hold = i;
	size = 0;
	while (buf[i] != '\n' && i < place)
	{
		size++;
		i++;
	}
	if (buf[i] == '\n')
	{
		i++;
		*run = 0;
	}
	*index = i;
	if (i == place)
		i = 0;
	return (str_line(buf, size, hold));
}

int				get_next_line(int fd, char **line)
{
	static char	buf[1 + BUFF_SIZE];
	static int	place;
	static int	index;
	char		*rtn;
	int			i;

	i = 1;
	while (i == 1)
	{
		if (index == place)
		{
			place = read(fd, buf, BUFF_SIZE);
		}
		if (place == 0)
			return (0);
		printf("%s",count(buf, place, &i, &index));
	}
	if (place > 0)
		return (1);
	return (0);
}

int				main(void)
{
	int		file;
	int		i;
	char	*hold4;

	i = 1;
	hold4 = NULL;
	file = open("test.txt", O_RDONLY);
	if (file == -1)
	{
		printf("fail");
		return (0);
	}
	while (i == 1)
	{
		i = get_next_line(file, &hold4);
		printf("---\n");
	}
	return (0);
}
