/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_help_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:30:42 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:30:47 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sch_s_help(t_list **start, t_list **first, t_srt *srt, t_list **lst)
{
	if (srt->max < srt->now)
	{
		srt->max = srt->now;
		*start = *first;
	}
	srt->now = 1;
	*lst = (*first)->next;
	*first = (*first)->next;
	srt->flag = 0;
	return (0);
}

static void	cr_srt(t_list *lst, t_srt *t)
{
	t->flag = 0;
	t->max = 0;
	t->now = 1;
	t->first = lst;
}

int	search_sort(t_list *lst, t_list **start)
{
	t_srt	t;

	cr_srt(lst, &t);
	while (lst->next)
	{
		if ((((int)lst->next->content < (int)t.first->content && t.flag > 1)
				|| t.flag == 0) && (int)lst->content < (int)lst->next->content)
		{
			if (t.now == 1)
				t.first = lst;
			++t.now;
		}
		else if ((int)lst->content > (int)lst->next->content && t.flag == 0
			&& (int)lst->next->content < (int)t.first->content)
		{
			++t.now;
			t.flag = 1;
		}
		else if (sch_s_help(start, &t.first, &t, &lst) == 0)
			continue ;
		lst = lst->next;
	}
	sch_s_help(start, &t.first, &t, &lst);
	return (t.max);
}

static int	rool_half(t_list **new, t_list *lst_a, t_list *lst_b)
{
	int		up;
	t_list	*first;

	first = lst_a;
	up = 0;
	while (first)
	{
		ft_lstadd_back(new, ft_lstnew(first->content));
		first = first->next;
	}
	while (is_sort(*new, lst_b) != 1)
	{
		ra_or_rb(new);
		++up;
	}
	return (up);
}

int	roll(t_list *lst_a, t_list *lst_b)
{
	int		up;
	int		down;
	t_list	*new;

	down = 0;
	new = NULL;
	up = rool_half(&new, lst_a, lst_b);
	down = up;
	while (down > 0)
	{
		rra_or_rrb(&new);
		--down;
	}
	while (is_sort(new, lst_b) != 1)
	{
		rra_or_rrb(&new);
		++down;
	}	
	lstclear(&new);
	if (up < down)
		return (1);
	return (-1);
}
