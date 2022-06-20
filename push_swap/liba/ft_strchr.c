/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:00:18 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/23 19:19:20 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*s1;
	int		l;

	i = 0;
	s1 = (char *)str;
	l = ft_strlen(s1);
	while (i <= l)
	{
		if (s1[i] == (char)ch)
			return (&s1[i]);
		++i;
	}
	return (0);
}
