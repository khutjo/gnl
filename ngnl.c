/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:37:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/10 14:51:52 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int				get_next_line(int fd, char **line)
{
	static char	*head;
	char		buf[1 + BUFF_SIZE];
	int			size;
	int			i;
	char		*swap;
	char		*rtn;

	i = 1;
	size = 1;
	rtn = NULL;
	while (i == 1)
	{
		if (head == NULL)
		{
			ft_bzero(buf, 1 + BUFF_SIZE);
			size = read(fd, buf, BUFF_SIZE);
			swap = rtn;
			rtn = ft_strjoin(swap, buf);
		}
		else
		{
			rtn = head;
			head = NULL;
		}
		if ((head = ft_strchr(rtn, '\n')))
		{
			head = ft_strdup(head + 1);
			ft_strclr(ft_strchr(rtn, '\n'));
			i = 0;
		}
		if (size == 0)
			i = 0;
	}
	(*line) = rtn;
	return (size);
}
