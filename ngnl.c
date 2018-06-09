/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:37:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/09 17:25:41 by kmaputla         ###   ########.fr       */
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
			rtn = ft_strjoin(rtn, buf);
		}
		else
		{
			rtn = head;
			head = NULL;
		}
		if ((head = ft_strdup(ft_strchr(rtn, '\n') + 1)))
		{
			ft_strclr(ft_strchr(rtn, '\n') - 1);
			i = 0;
		}
	}
	(*line) = rtn;
	return (size);
}
