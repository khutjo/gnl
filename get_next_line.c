/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:08:47 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/13 17:11:11 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*search(t_list **str, size_t fd)
{
	t_list *run;
	t_list *hold;

	run = (*str);
	hold = NULL;
	while (run != NULL && run->content_size != fd)
	{
		hold = run;
		run = run->next;
	}
	if (run == NULL)
	{
		ft_lstadd(str, ft_lstnew(0, 0));
		(*str)->content_size  = fd;
		return (*str);
	}
	else if (run->content_size == fd)
		return (run);
	return (0);
}

static	void	join(char **line, char *buf)
{
	char *temp;

	temp = 0;
	if ((*line) == NULL)
	   (*line) = ft_strdup(buf);
	else
	{
		temp = (*line);
		(*line) = ft_strjoin((*line), buf);
		free(temp);
	}
}

int	get_next_line(int fd, char **line)
{
	static	t_list	*save;
	char			buf[1 + BUFF_SIZE];
	t_list			*hold;
	int				size;
	int				i;

	i = 1;
	size = 1;
	if (fd < 0|| !line)
		return (-1);
	(*line) = NULL;
	hold = search(&save, (size_t)fd);
	while (i == 1 && size > 0)
	{
		if (hold->content == NULL)
		{
			ft_bzero(buf, BUFF_SIZE);
			size = read(fd, buf, BUFF_SIZE);
			join(line, buf);
		}
		else
		{
			(*line) = hold->content;
			free(hold->content = NULL);
		}
		if ((hold->content = ft_strchr((*line), '\n')))
		{
			hold->content = ft_strdup(hold->content + 1);
			ft_strclr(ft_strchr((*line), '\n'));
			i = 0;
		}
	}
	if (size > 1)
		size = 1;
	return (size);
}

