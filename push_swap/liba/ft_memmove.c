/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:41:01 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/13 14:22:14 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*ld;
	const char	*ls;

	if (!src && !dst)
		return (0);
	s = (const char *)src;
	d = (char *)dst;
	if (d < s)
		while (len--)
			*(d++) = *(s++);
	else
	{
		ld = d + (len - 1);
		ls = s + (len - 1);
		while (len--)
			*(ld--) = *(ls--);
	}
	return (dst);
}
