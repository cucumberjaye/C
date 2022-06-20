/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:25:34 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/13 13:41:13 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t count)
{
	size_t	i;
	char	*strdest;
	char	*strsrc;

	if (!src && !dest)
		return (0);
	strsrc = (char *)src;
	strdest = (char *)dest;
	i = 0;
	while (i < count)
	{
		strdest[i] = strsrc[i];
		++i;
	}
	return (dest);
}
