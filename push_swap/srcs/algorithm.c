/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:30:58 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:31:00 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*first_step(t_list *lst, int *max, t_list **start)
{	
	if (lst->next == *start)
	{
		if ((int)lst->content > (int)(*start)->content
			&& (int)lst->content < (int)(*start)->next->content)
		{
			++(*max);
			write (1, "sa\n", 3);
			return (sa_or_sb(lst));
		}
	}
	else if (lst == *start)
	{
		if ((int)lst->content > (int)(*start)->next->content
			&& (*start)->next->next)
		{
			if ((int)(*start)->content < (int)(*start)->next->next->content)
			{
				++(*max);
				write (1, "sa\n", 3);
				*start = lst->next;
				return (sa_or_sb(lst));
			}
		}
	}
	return (lst);
}

int	is_sort(t_list *lst_a, t_list *lst_b)
{
	t_list	*tmp;

	tmp = lst_a;
	if (lst_b)
		return (0);
	while (tmp->next)
	{
		if ((int)tmp->content < (int)tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

static int	sch_min(t_list *lst_a)
{
	int	min;

	min = (int)lst_a->content;
	while (lst_a)
	{
		if ((int)lst_a->content < min)
			min = (int)lst_a->content;
		lst_a = lst_a->next;
	}
	return (min);
}

static void	short1(t_list **lst_a, t_list **start, t_par *control)
{
	t_list	*tmp;
	int		len;

	tmp = *start;
	len = control->lenght;
	if (control->lenght == 2)
	{
		if ((int)(*start)->content > (int)(*start)->next->content)
		{
			*start = (*start)->next;
			*lst_a = sa_or_sb(*lst_a);
			control->lenght = search_sort(*lst_a, start);
			if (control->lenght == len)
			{
				*start = tmp;
				control->lenght = len;
				*lst_a = sa_or_sb(*lst_a);
				return ;
			}
			write(1, "sa\n", 3);
		}
	}
}

void	algorithm(t_list **lst_a, t_list *lst_b, t_par *control)
{
	t_list	*start;

	start = NULL;
	control->lenght = search_sort(*lst_a, &start);
	short1(lst_a, &start, control);
	control->elems = len_lst(*lst_a);
	while (is_sort(*lst_a, lst_b) != 1)
	{
		control->min = sch_min(*lst_a);
		if (*lst_a == start)
			control->lenght = search_sort(*lst_a, &start);
		*lst_a = first_step(*lst_a, &control->lenght, &start);
		if (len_lst(*lst_a) == control->lenght && !lst_b)
		{
			win(lst_a, lst_b, roll(*lst_a, lst_b));
			return ;
		}
		if (score_a(*lst_a, control, start)
			< score_b(*lst_a, lst_b, start, control) || !lst_b)
			if_score_a(lst_a, &lst_b, control, &start);
		else
			if_score_b(lst_a, &lst_b, control, &start);
		control = free_con(control);
	}
}
