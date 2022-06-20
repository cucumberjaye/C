/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:05:05 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/21 16:01:57 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

const char	*new_s1(char const *new, char const *set, int *k)
{
	int		i;
	int		l;

	if (!new)
		return (NULL);
	while (*new)
	{
		l = 0;
		i = 0;
		while (set[i])
		{
			if (*new == set[i])
				l++;
			++i;
		}
		if (l == 0)
			return (new);
		++new;
		++(*k);
	}
	return (new);
}

const char	*new_s2(const char *new, char const *set)
{
	int	i;
	int	l;
	int	k;

	k = ft_strlen((char *)new);
	l = 0;
	while (*new)
		++new;
	--new;
	while (k--)
	{	
		i = 0;
		l = 0;
		while (set[i])
		{
			if (*new == set[i])
				l++;
			++i;
		}
		if (l == 0)
			return (new);
		--new;
	}
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*sub;
	const char	*res;
	int			i;
	int			l;
	char		*str;

	if (!s1)
		return (NULL);
	i = 0;
	l = 0;
	sub = new_s1(s1, set, &l);
	res = new_s2(s1, set);
	while ((int)sub <= (int)res)
	{
		++i;
		--res;
	}
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	while ((int)sub <= (int)res + i)
		*(str++) = *(sub++);
	*str = '\0';
	return (str - i);
}
