/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:42:58 by cjaye             #+#    #+#             */
/*   Updated: 2021/11/21 13:43:00 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *src, int l)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (l + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < l)
	{
		new[i] = src[i];
		++i;
	}
	new[l] = '\0';
	return (new);
}

char	*ft_realloc(char *str, int len, int size)
{
	char		*sec;
	int			i;

	i = -1;
	sec = (char *)malloc(sizeof(char) * (size + len + 2));
	if (!sec)
		return (NULL);
	while (++i < len)
		sec[i] = str[i];
	sec[i] = '\0';
	sec[i + 1] = '\0';
	free(str);
	return (sec);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*src;
	char	*s1;
	size_t	i;

	i = 0;
	src = (void *)malloc(size * num);
	if (!src)
		return (NULL);
	s1 = (char *)src;
	while (i < num * size)
		s1[i++] = '\0';
	return ((void *)s1);
}

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		++l;
	return (l);
}
