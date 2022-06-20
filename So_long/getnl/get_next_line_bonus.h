/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:42:45 by cjaye             #+#    #+#             */
/*   Updated: 2021/11/21 13:42:46 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(char *src, int l);
char	*ft_realloc(char *str, int len, int size);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t num, size_t size);

#endif
