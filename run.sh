
read -p "enter  buffer size  " num

echo "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:57:21 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/19 10:24:59 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include \"./libft/libft.h\"
# define BUFF_SIZE $num

int	get_next_line(const int fd, char **line);
#endif" > get_next_line.h

make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes \
		-o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

