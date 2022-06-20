/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:03:06 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/21 15:55:47 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

const char	*space(const char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\f' || *str == '\v')
			++str;
		else
			break ;
	}
	return (str);
}

const char	*plmin(const char *str, int *znak)
{
	while (*str)
	{
		if (*str == '+')
			++str;
		else if (*str == '-')
		{
			*znak = -1;
			++str;
		}
		break ;
	}
	return (str);
}

int	diglen(int s)
{
	int	l;

	l = 0;
	while (s < -9)
	{
		s /= 10;
		++l;
	}
	return (l);
}

int	proverka(const char *str, long s, int znak)
{
	if (znak == 1 && - s > 922337203685477580)
		return (-1);
	if (znak == 1 && - s == 922337203685477580 && *str > '7')
		return (-1);
	if (s < -922337203685477580)
		return (0);
	if (s == 922337203685477580 && *str > '8')
		return (0);
	return (1);
}

long	ft_atoi(const char *str)
{
	int		znak;
	long	s;
	int		k;

	s = 0;
	k = 0;
	znak = 1;
	str = space(str);
	str = plmin(str, &znak);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (proverka(str, s, znak) == -1 || proverka(str, s, znak) == 0)
				return (proverka(str, s, znak));
			s = 10 * s - (*str - '0');
		}
		else
			break ;
		++str;
	}
	if (znak == 1)
		return (-s);
	return (s);
}
