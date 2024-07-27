/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2024/07/27 20:43:21 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*str_copy;
	size_t	len;

	len = ft_strlen(str);
	str_copy = (char *)malloc(len +1);
	if (!str_copy)
		return (NULL);
	ft_memcpy(str_copy, str, len);
	str_copy[len] = '\0';
	return (str_copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = ft_calloc(len + 1, 1);
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
	return (substr);
}
