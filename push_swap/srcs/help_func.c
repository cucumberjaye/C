/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:31:20 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:31:23 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_lst(t_list *lst_b)
{
	int	l;

	l = 0;
	while (lst_b)
	{
		++l;
		lst_b = lst_b->next;
	}
	return (l);
}

int	maximus(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

t_par	*free_con(t_par *control)
{
	int	len;
	int	med;
	int	elem;

	med = control->med;
	len = control->lenght;
	elem = control->elems;
	free(control);
	control = cr_control();
	control->lenght = len;
	control->med = med;
	control->elems = elem;
	return (control);
}
