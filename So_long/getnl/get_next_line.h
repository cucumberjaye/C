/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:34:10 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/27 16:34:14 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(char *src, int l);
char	*ft_realloc(char *str, int len, int size);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t num, size_t size);

#endif
