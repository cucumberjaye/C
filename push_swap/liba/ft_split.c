/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:59:51 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/26 15:13:22 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

const char	*skip_sep(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			++s;
		else
			break ;
	}
	return (s);
}

int	words_count(char const *s, char c)
{
	int	count;
	int	l;

	s = skip_sep(s, c);
	l = ft_strlen((char *)s);
	count = 0;
	while (l--)
	{
		l = ft_strlen((char *)s);
		if (*s != c && *s != '\0')
		{
			++s;
			continue ;
		}
		if (*s == '\0' && *(s - 1) == c)
			break ;
		++count;
		s = skip_sep(s, c);
	}
	return (count);
}

char const	*words_len(char const *s, char c, int *k)
{
	*k = 0;
	s = skip_sep(s, c);
	while (*s != c && *s)
	{
		++(*k);
		++s;
	}
	return (s);
}

char	**half_split(const char *s, int l, char c, char **res)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < l)
	{
		s = words_len(s, c, &k);
		res[i] = (char *)malloc(sizeof(char) * (k + 1));
		if (!res[i])
			return (NULL);
		j = -1;
		s = s - k;
		while (++j < k)
			res[i][j] = *(s++);
		res[i][k] = '\0';
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		l;

	if (!s)
		return (0);
	l = words_count(s, c);
	res = (char **)malloc(sizeof(char *) * (l + 1));
	if (!res)
		return (NULL);
	res = half_split(s, l, c, res);
	if (!res)
		return (NULL);
	res[l] = NULL;
	return (res);
}
