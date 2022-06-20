/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:22:17 by cjaye             #+#    #+#             */
/*   Updated: 2022/01/04 16:22:24 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	flag_x(unsigned int num);
int	flag_proc(void);
int	flag_di(int num);
int	flag_u(unsigned int num);
int	flag_upx(unsigned int num);
int	flag_p(unsigned long num);
int	ft_printf(const char *format, ...);
int	flag_c(int c);
int	flag_s(char *str);

#endif
