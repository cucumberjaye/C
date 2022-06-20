/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:40:50 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/23 14:38:28 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	step(int n)
{
	int	d;

	d = 1;
	while (n < -9)
	{
		n /= 10;
		d *= 10;
	}
	return (d);
}

void	put(int n, int d, int fd)
{
	char	c;

	while (d > 0)
	{
		c = - (n / d) + '0';
		write(fd, &c, 1);
		n %= d;
		d /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		znak;
	int		d;

	znak = -1;
	if (n >= 0)
	{
		n = -n;
		znak = 1;
	}
	d = step(n);
	if (znak == -1)
		write(fd, "-", 1);
	put(n, d, fd);
}
