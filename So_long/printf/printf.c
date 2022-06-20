/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:22:29 by cjaye             #+#    #+#             */
/*   Updated: 2022/01/04 16:22:31 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	eval_type(va_list args, const char *format, int *i)
{
	++(*i);
	if (format[*i] == 'c')
		return (flag_c(va_arg(args, int)));
	else if (format[*i] == 's')
		return (flag_s(va_arg(args, char *)));
	else if (format[*i] == 'i' || format[*i] == 'd')
		return (flag_di(va_arg(args, int)));
	else if (format[*i] == 'u')
		return (flag_u(va_arg(args, unsigned int)));
	else if (format[*i] == 'x')
		return (flag_x(va_arg(args, unsigned int)));
	else if (format[*i] == 'X')
		return (flag_upx(va_arg(args, unsigned int)));
	else if (format[*i] == 'p')
		return (flag_p(va_arg(args, unsigned long)));
	else if (format[*i] == '%')
		return (flag_proc());
	--(*i);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		i;
	int		wordlen;

	i = -1;
	length = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			wordlen = eval_type(args, format, &i);
			if (wordlen == -1)
				length += write(1, &format[i], 1);
			else
				length += wordlen;
		}
		else
			length += write(1, &format[i], 1);
	}
	va_end(args);
	return (length);
}
