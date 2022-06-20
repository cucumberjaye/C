/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:22:06 by cjaye             #+#    #+#             */
/*   Updated: 2022/01/04 16:22:09 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/so_long.h"

static unsigned long	find_del(unsigned long num, unsigned long syst)
{
	unsigned long	del;

	del = 1;
	while (num > syst - 1)
	{
		del *= syst;
		num /= syst;
	}
	return (del);
}

int	flag_u(unsigned int num)
{
	unsigned int	del;
	char			c;
	int				count;

	num += 4294967295 + 1;
	count = 0;
	del = find_del(num, 10);
	while (del > 0)
	{
		c = num / del + '0';
		write(1, &c, 1);
		num %= del;
		del /= 10;
		++count;
	}
	return (count);
}

int	flag_x(unsigned int num)
{
	unsigned int	del;
	char			c;
	unsigned int	digit;
	int				count;

	num += 4294967295 + 1;
	count = 0;
	del = find_del(num, 16);
	while (del > 0)
	{
		digit = num / del;
		if (digit > 9)
			c = digit - 10 + 'a';
		else
			c = digit + '0';
		write(1, &c, 1);
		num %= del;
		del /= 16;
		++count;
	}
	return (count);
}

int	flag_upx(unsigned int num)
{
	unsigned int	del;
	char			c;
	unsigned int	digit;
	int				count;

	num += 4294967295 + 1;
	count = 0;
	del = find_del(num, 16);
	while (del > 0)
	{
		digit = num / del;
		if (digit > 9)
			c = digit - 10 + 'A';
		else
			c = digit + '0';
		write(1, &c, 1);
		num %= del;
		del /= 16;
		++count;
	}
	return (count);
}

int	flag_p(unsigned long num)
{
	unsigned long	del;
	char			c;
	unsigned long	digit;
	int				count;

	count = write(1, "0x", 2);
	del = find_del(num, 16);
	while (del > 0)
	{
		digit = num / del;
		if (digit > 9)
			c = digit - 10 + 'a';
		else
			c = digit + '0';
		write(1, &c, 1);
		num %= del;
		del /= 16;
		++count;
	}
	return (count);
}
