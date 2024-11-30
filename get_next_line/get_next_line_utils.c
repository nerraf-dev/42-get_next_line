/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2024/11/30 21:47:58 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	gnl_find_nl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

char	*gnl_strdup(char *str)
{
	char	*str_copy;
	int		len;
	int		i;

	i = 0;
	len = gnl_strlen(str);
	str_copy = (char *)malloc(len +1);
	if (!str_copy)
		return (NULL);
	while (str[i])
	{
		str_copy[i] = str[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (start > gnl_strlen(s))
		return (gnl_strdup(""));
	if (start + len > gnl_strlen(s))
		len = gnl_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	i = 0;
	j = start;
	while (i < len)
	{
		substr[i] = s[j];
		i++;
		j++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*gnl_str_join(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*s3;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	s3 = (char *)malloc(s1_len + s2_len + 1);
	if (!s3)
		return (gnl_free_buf((char **)&s1));
	i = 0;
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		s3[i] = *s2++;
		i++;
	}
	s3[i] = '\0';
	gnl_free_buf((char **)&s1);
	return (s3);
}
