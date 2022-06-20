/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/01/04 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/so_long.h"

int	flag_c(int c)
{
	return (write(1, &c, 1));
}

int	flag_proc(void)
{
	return (write(1, "%", 1));
}

int	flag_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}

static int	search_del(int num)
{
	int	del;

	del = 1;
	while (num < -9)
	{
		del *= 10;
		num /= 10;
	}
	return (del);
}

int	flag_di(int num)
{
	int		del;
	int		flag;
	char	c;

	flag = 1;
	if (num >= 0)
	{
		num = -num;
		flag = 0;
	}
	if (flag == 1)
		write(1, "-", 1);
	del = search_del(num);
	while (del > 0)
	{
		c = -(num / del) + '0';
		write(1, &c, 1);
		num %= del;
		del /= 10;
		++flag;
	}
	return (flag);
}
