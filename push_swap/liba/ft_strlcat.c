/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:37:44 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/23 17:48:54 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	i = ft_strlen(dst);
	k = i;
	if (k > size || (dst[0] == '\0' && size == 0))
		return (size + ft_strlen((char *)src));
	while (i < size - 1 && src[i - k])
	{
		dst[i] = src[i - k];
		++i;
	}
	dst[i] = '\0';
	return (k + ft_strlen((char *)src));
}
