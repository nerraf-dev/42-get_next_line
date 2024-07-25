/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:21:52 by sfarren           #+#    #+#             */
/*   Updated: 2024/07/25 17:33:40 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buf;
	char		*line;
	int			ret;
	int			newline_index;
	char		*temp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (remainder)
		{
			temp = ft_strjoin(remainder, buf);
			free(remainder);
			remainder = temp;
		}
		else
			remainder = ft_strdup(buf);
		newline_index = find_newline(remainder);
		if (newline_index >= 0)
		{
			line = malloc(newline_index + 2);
			if (!line)
			{
				free(buf);
				return (NULL);
			}
			ft_strlcpy(line, remainder, newline_index + 2);
			temp = ft_strdup(remainder + newline_index + 1);
			free(remainder);
			remainder = temp;
			free(buf);
			return (line);
		}
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (remainder && *remainder)
	{
		line = ft_strdup(remainder);
		free(remainder);
		remainder = NULL;
	}
	free(buf);
	return (line);
}
