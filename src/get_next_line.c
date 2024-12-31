/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:48:24 by sfarren           #+#    #+#             */
/*   Updated: 2024/11/30 21:48:35 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Finds the position of the first occurrence of a
 * newline character ('\n') in a string.
 *
 * @param str The string to search for a newline character.
 * @return The position of the first newline character in
 *   the string, or 0 if not found.
 */

char	*gnl_free_buf(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (NULL);
}

char	*gnl_new_buffer(char *buf, int fd)
{
	char	*new_buf;
	int		bytes_read;

	bytes_read = 1;
	new_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!new_buf)
		return (gnl_free_buf(&buf));
	while (bytes_read > 0 && !gnl_find_nl(buf))
	{
		bytes_read = read(fd, new_buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			gnl_free_buf(&new_buf);
			return (gnl_free_buf(&buf));
		}
		new_buf[bytes_read] = '\0';
		if (!buf && bytes_read > 0)
			buf = gnl_strdup(new_buf);
		else if (bytes_read > 0)
			buf = gnl_str_join(buf, new_buf);
	}
	gnl_free_buf(&new_buf);
	return (buf);
}

char	*gnl_result_buf(char **buf)
{
	char	*temp;
	char	*result_buf;
	int		nl_loc;

	temp = gnl_strdup(*buf);
	gnl_free_buf(buf);
	if (!temp)
		return (gnl_free_buf(&temp));
	if (!gnl_find_nl(temp))
	{
		result_buf = gnl_strdup(temp);
		gnl_free_buf(&temp);
		return (result_buf);
	}
	nl_loc = gnl_find_nl(temp);
	result_buf = gnl_substr(temp, 0, nl_loc);
	if (!result_buf)
		return (gnl_free_buf(&temp));
	*buf = gnl_substr(temp, nl_loc, gnl_strlen(temp) - nl_loc);
	gnl_free_buf(&temp);
	if (!*buf || !*buf[0])
		gnl_free_buf(buf);
	return (result_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf || !gnl_find_nl(buf))
		buf = gnl_new_buffer(buf, fd);
	if (!buf)
		return (NULL);
	return (gnl_result_buf(&buf));
}
