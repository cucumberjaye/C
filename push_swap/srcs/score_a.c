/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:32:30 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:32:33 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	score_a(t_list *lst_a, t_par *control, t_list *start)
{
	int	count;

	if (len_lst(lst_a) == control->lenght)
		return (1000);
	count = 0;
	if (start != lst_a)
		return (-1000);
	while (lst_a)
	{
		++count;
		lst_a = lst_a->next;
	}
	if (count > control->lenght)
		return (-1001);
	else
		return (1000);
}

static void	push_med(t_list **lst_b, t_par *control)
{
	if (len_lst(*lst_b) > 1)
	{
		if ((int)(*lst_b)->content > control->med)
		{
			ra_or_rb(lst_b);
			write(1, "rb\n", 3);
		}
	}
}

static int	half_isa(t_list **lst_a, t_list **start, t_par *control)
{
	t_list	*tmp;

	tmp = *lst_a;
	*lst_a = first_step(*lst_a, &control->lenght, start);
	if (tmp != *lst_a)
		return (1);
	if ((int)(*lst_a)->content < (int)(*start)->content
		&& (*lst_a)->next == *start)
	{
		++control->lenght;
		*start = *lst_a;
		return (1);
	}
	return (0);
}

void	if_score_a(t_list **lst_a, t_list **lst_b, t_par *control,
	t_list **start)
{
	if (score_a(*lst_a, control, *start) == -1000)
	{
		pa_or_pb(lst_b, lst_a);
		write(1, "pb\n", 3);
		if (control->elems > 50)
			push_med(lst_b, control);
	}
	if (score_a(*lst_a, control, *start) == -1001)
	{
		rra_or_rrb(lst_a);
		write(1, "rra\n", 4);
		if (half_isa(lst_a, start, control) == 1)
			return ;
		pa_or_pb(lst_b, lst_a);
		write(1, "pb\n", 3);
		if (control->elems > 50)
			push_med(lst_b, control);
	}
}
