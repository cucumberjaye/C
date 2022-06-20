/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:06:44 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/23 19:14:07 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int n)
{
	int		i;
	int		l;
	int		k;

	l = ft_strlen(little);
	if (l == 0)
		return ((char *)big);
	i = 0;
	k = 1;
	if (n < 0)
		n += ft_strlen(big);
	while (big[i] && i < n - l + 1)
	{
		if (big[i] == little[0])
			if (ft_strncmp(&big[i], little, l) == 0)
				return (&((char *)big)[i]);
		++i;
	}
	return (0);
}
