/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:11 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/11 19:13:29 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!tmp || !tmp[i])
		return (NULL);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static void	ft_offset(char *buffer, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\n')
		i++;
	while (tmp[i] != '\0')
	{
		buffer[j] = tmp[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

static char	*ft_free(char *tmp, char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
	free(tmp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	int			res;
	char		*tmp;
	char		*line;

	res = 1;
	tmp = (char *) ft_strdup(buffer[fd]);
	if (fd < 0 || BUFFER_SIZE <= 0 || tmp == NULL)
		return (ft_free(tmp, buffer[fd]));
	while (res != 0)
	{
		res = read(fd, buffer[fd], BUFFER_SIZE);
		if (res == -1)
			return (ft_free(tmp, buffer[fd]));
		buffer[fd][res] = '\0';
		tmp = ft_strjoin(tmp, buffer[fd]);
		if (ft_strchr(tmp, '\n') || tmp == NULL)
			break ;
	}
	line = ft_get_line(tmp);
	ft_offset(buffer[fd], tmp);
	free(tmp);
	return (line);
}

/*int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("read_error.txt", O_RDONLY);
	printf("1. %d 2. %d\n", fd1, fd2);
	line = get_next_line(fd1);
	printf("1. %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("2. %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("1. %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("2. %s", line);
	free(line);
	return (0);
}
*/
