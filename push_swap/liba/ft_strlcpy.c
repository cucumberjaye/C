/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:37:28 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/21 16:01:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (src[0] == '\0')
	{
		dst[0] = src[0];
		return (0);
	}
	l = ft_strlen((char *)src);
	if (size == 0 || sizeof(dst) == 0)
		return (l);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (l);
}
