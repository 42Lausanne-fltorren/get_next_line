/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:11:53 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/07 15:33:52 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (count--)
		((char *)ptr)[count] = 0;
	return (ptr);
}

static size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	char			*d;
	char			*s;
	unsigned int	dlen;
	unsigned int	n;

	d = dest;
	s = src;
	n = size;
	while (n-- != 0 && *d)
		d++;
	dlen = d - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	len;
	char	*join;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	while (str2[i] && str2[i++] != '\n')
		;
	len = ft_strlen(str1) + i + 1;
	join = (char *) ft_calloc(len, 1);
	if (!join)
		return (NULL);
	ft_strlcat(join, str1, len);
	ft_strlcat(join, str2, len);
	free(str1);
	return (join);
}
