/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:11 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/07 21:32:13 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char *buffer)
{
	int		res;

	res = read(fd, buffer, BUFFER_SIZE);
	if (res > 0)
		buffer[res] = '\0';
	else
		buffer[0] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	offset;
	int			res;
	char		*line;
	int			i;

	line = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (offset == 0 || offset >= BUFFER_SIZE)
	{
		res = ft_read(fd, buffer);
		offset = 0;
	}
	i = 0;
	while (buffer[offset + i] != '\n' && res > 0)
	{
		if (buffer[offset + i] == '\0')
		{
			line = ft_strjoin(line, buffer + offset);
			res = ft_read(fd, buffer);
			offset = 0;
			i = 0;
		}
		i++;
	}
	line = ft_strjoin(line, buffer + offset);
	offset += i + 1;
	return (line);
}

int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
