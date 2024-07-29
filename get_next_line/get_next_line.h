/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:45:21 by sfarren           #+#    #+#             */
/*   Updated: 2024/07/27 23:56:11 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
// for mallloc and free
# include <stdlib.h>
// for read
# include <unistd.h>
# include <limits.h>

//TODO: Remove standard fucntions and replace with own
// # include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
char		*ft_strdup(char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_gnl_join(char const *s1, char const *s2);
char		*ft_free_buf(char **str);
int			ft_find_nl(const char *str);

#endif
