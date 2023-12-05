/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:11 by fltorren          #+#    #+#             */
/*   Updated: 2023/12/05 12:59:52 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_str(int fd, char *str)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_str(fd, str[fd]);
	if (!str)
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_new_str(str[fd]);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	line = get_next_line(fd);
	printf("1. %s", line);
	free(line);
	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("2. %s", line);
	free(line);
	close(fd);
	line = get_next_line(fd);
	printf("3. %s", line);
	free(line);
	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("4. %s", line);
	free(line);
	line = get_next_line(fd);
	printf("5. %s", line);
	free(line);
	close(fd);
	return (0);
}
*/
