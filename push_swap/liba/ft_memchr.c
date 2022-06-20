/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:34:25 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/23 19:17:34 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *arr, int ch, size_t n)
{
	char	*str;
	size_t	i;
	void	*s1;

	i = 0;
	str = (char *)arr;
	while (i < n)
	{
		if (str[i] == (char)ch)
		{
			s1 = (void *)str;
			return (&s1[i]);
		}
		++i;
	}
	return (0);
}
