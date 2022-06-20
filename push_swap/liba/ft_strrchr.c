/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:05:16 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/23 17:35:39 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	int		k;
	char	*s1;
	int		l;

	k = -1;
	i = 0;
	s1 = (char *)str;
	l = ft_strlen(s1);
	while (i <= l)
	{
		if (s1[i] == (unsigned char)ch)
			k = i;
		++i;
	}
	if (k >= 0)
		return (&s1[k]);
	return (0);
}
