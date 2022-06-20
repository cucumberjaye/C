/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:54:14 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/17 14:22:00 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

unsigned int	lent(char const *s)
{
	unsigned int	l;

	l = 0;
	while (s[l])
		++l;
	return (l);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	l;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	l = lent(s);
	while (i < l)
	{
		new[i] = f(i, new[i]);
		++i;
	}
	return (new);
}
