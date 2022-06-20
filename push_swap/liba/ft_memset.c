/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:58:43 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/13 13:16:03 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	char	c;
	size_t	i;
	char	*str;

	str = (char *)buf;
	i = 0;
	c = ch;
	while (i < count)
	{
		str[i] = c;
		++i;
	}
	return (buf);
}
