/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:58:48 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/07 16:58:50 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#define BUFF_SIZE 32 

static	int		next_line(char *buf, int place)
{
	int	i;

	i = 0;
	if (place == 0)
		return (-2);
	while (i < place && buf[i] != '\n')
	{
		i++;
		printf("%c === %d", buf[i], place);
	}
	if (i == place)
		return (-1);
	return (i);
}

static	void	new(char *temp, char *buf, int place)
{
	int		i;
	int		index;
	char	*new_str;

	i = 0;
	index = -1;
	new_str = NULL;
	if (temp)
		while (temp[i])
			i++;
	if ((new_str = (char *)malloc(sizeof(char) * (1 +(place + i)))))
	{
		while (temp && ++index < i)
			new_str[index] = temp[index];
		i = -1;
		while (++i < place)
		{
			new_str[index] = buf[i];
			index++;
		}
		new_str[index] = '\0';
	}
}

int				get_next_line(int fd, char **line)
{
	static	char	buf[1 + BUFF_SIZE];
	static	int		index;
	static	int		place;
	char			*temp;
	int				count;

	printf("K");
	temp = NULL;
	while (index == 0)
	{
		if (index == 0 && place == 0)
			place = read(fd, buf, BUFF_SIZE);
		count = next_line(buf, place);
		if (count == -1)
		{
			return (0);	
//			new(temp, buf, place);
		}
		if (count > 0)
		{
			printf("h");
//			new(temp, buf, count);
			index = 1;
			place = 1;
		}
		if (count == -2)
			index = 1;
	}
	*line = temp;
	if (index == 2)
		return (0);
	if (index == 1)
	{
		index = 0;
		return (1);
	}
	return (index);
}

int				main(void)
{
	int		file;
	int		i;
	char	*hold1;
	char	*hold2;
	char	*hold3;
	char	*hold4;

	i = 1;
	hold3 = NULL;
	hold1 = NULL;
	hold2 = NULL;
	hold4 = NULL;
	file = open("test.txt", O_RDONLY);
	if (file == -1)
	{
		printf("fail");
		return (0);
	}
//	while (i)
	{
		printf("(");
		i = get_next_line(file, &hold1);
		printf("---%s\n", hold1);
		i = get_next_line(file, &hold2);
		printf("---%s\n", hold2);
		i = get_next_line(file, &hold3);
		printf("---%s\n", hold3);
	   	i = get_next_line(file, &hold4);
		printf("---%s\n", hold4);
		
	}
	return (0);
}
