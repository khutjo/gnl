/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:58:48 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/06 17:13:44 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#define BUFF_SIZE 32 

static	char	*read_line(int fd, char *rtn_str, int *i)
{
	static	char	buf[1 + BUFF_SIZE];
	static	int		index;
	static	int		place;

	ft_strclr(rtn_str);
	free(rtn_str);
	rtn_str = NULL;
	if (index == place)
	{
		place = read(fd, buf, BUFF_SIZE);;
	}
	while (buf[index] != '\n' && buf[index] != '\0')
		index++;
	if (index == place)
	{
		index = 0;
		place = 0;
		rtn_str = ft_strdup(buf);
		ft_bzero(buf, BUFF_SIZE);
	}
	else if (index < place && buf[index] == '\n')
	{
		*i = 1;
		rtn_str = ft_strnew(index);
		ft_memcpy(rtn_str, buf, index++);
		index++;
	}
	return (rtn_str);
}

int				get_next_line(int const fd, char **line)
{
	char	*swap;
	char	*hold;
	int		run;
	int		i;

	i = 0;
	run = 0;
	swap = NULL;
	hold = NULL;
	while (i != 1)
	{
		run = 1;
		hold = read_line(fd, hold, &i);
		if (hold != NULL)
			 swap = ft_strjoin(swap, hold);
	}
	(*line) = swap;
	return (i);
}

int				main(void)
{
	int		file;
	int		i;
	char	*hold;

	i = 1;
	hold = NULL;
	file = open("new", O_RDONLY);
	if (file == -1)
	{
		printf("fail");
		return (0);
	}
//	while (i)
	{
		i = get_next_line(file, &hold);
		printf("---%s\n", hold);
		i = get_next_line(file, &hold);
		printf("--- %s\n", hold);
	}
	return (0);
}
