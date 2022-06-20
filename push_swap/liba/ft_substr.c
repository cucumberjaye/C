/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:17:08 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/21 16:03:20 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	l;
	int				i;
	char			*sub;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_calloc(1, 1));
	l = start;
	i = 0;
	while (s[l++] && len--)
		++i;
	new = (char *)malloc(sizeof(char) * i + 1);
	if (!new)
		return (NULL);
	sub = new;
	while (i--)
	{
		*(new++) = s[start++];
	}
	*new = '\0';
	return (sub);
}
