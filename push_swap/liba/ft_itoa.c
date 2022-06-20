/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:02:21 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/23 15:18:46 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*create(int n, int l, int znak, int pow)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (l + 1 + znak));
	if (res == NULL)
		return (NULL);
	if (znak == 1)
		res[i++] = '-';
	if (i != 0)
		++l;
	while (pow > 0)
	{
		res[i] = -(n / pow) + '0';
		n %= pow;
		pow /= 10;
		++i;
	}
	res[l] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		l;
	int		znak;
	int		pow;
	int		r;

	pow = 1;
	znak = 1;
	if (n >= 0)
	{
		n = -n;
		znak = 0;
	}
	r = n;
	l = 1;
	while (n < -9)
	{
		n /= 10;
		++l;
		pow *= 10;
	}
	return (create(r, l, znak, pow));
}
