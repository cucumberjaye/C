/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:32:45 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:32:47 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	score_b(t_list *lst_a, t_list *lst_b, t_list *start, t_par *control)
{
	int		lena;
	int		lenb;
	t_list	*before;

	start = lst_a;
	lenb = len_lst(lst_b);
	lena = len_lst(lst_a);
	while (lst_b)
	{
		lst_a = start;
		control->score = 0;
		before = sh_before(lst_a);
		while (lst_a)
		{
			if (try_2(lst_a, lst_b, control, before) == 1)
				upd(control, lena, lenb);
			++control->score;
			before = lst_a;
			lst_a = lst_a->next;
		}
		++control->sc_b;
		lst_b = lst_b->next;
	}
	return (control->final_score);
}

static void	isb_1(t_list **lst_a, t_list **lst_b, t_par *control)
{
	if (control->m_a > 0 && control->m_b > 0)
	{
		while (control->m_b > 0 && control->m_a > 0)
		{
			control->m_b--;
			control->m_a--;
			rr(lst_a, lst_b);
		}
	}
	if (control->m_a < 0 && control->m_b < 0)
	{
		while (control->m_b < 0 && control->m_a < 0)
		{
			control->m_b++;
			control->m_a++;
			rrr(lst_a, lst_b);
		}
	}
}

static void	isb_2(t_list **lst_a, t_par *control)
{
	if (control->m_a > 0)
	{
		while (control->m_a-- > 0)
		{
			ra_or_rb(lst_a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (control->m_a++ < 0)
		{
			rra_or_rrb(lst_a);
			write(1, "rra\n", 4);
		}
	}
}

static void	isb_3(t_list **lst_b, t_par *control)
{
	if (control->m_b > 0)
	{
		while (control->m_b-- > 0)
		{
			ra_or_rb(lst_b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while (control->m_b++ < 0)
		{
			rra_or_rrb(lst_b);
			write(1, "rrb\n", 4);
		}
	}
}

void	if_score_b(t_list **lst_a, t_list **lst_b,
	t_par *control, t_list **start)
{
	isb_1(lst_a, lst_b, control);
	isb_2(lst_a, control);
	isb_3(lst_b, control);
	if ((int)(*lst_b)->content < (int)(*start)->content && *lst_a == *start)
		*start = *lst_b;
	pa_or_pb(lst_a, lst_b);
	write(1, "pa\n", 3);
	++control->lenght;
}
