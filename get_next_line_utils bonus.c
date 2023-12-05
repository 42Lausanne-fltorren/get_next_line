/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:11:53 by fltorren          #+#    #+#             */
/*   Updated: 2023/12/05 12:57:49 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			str[i] = str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		str[i] = str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		str[j++] = str[i++];
	str[j] = '\0';
	free(str);
	return (str);
}