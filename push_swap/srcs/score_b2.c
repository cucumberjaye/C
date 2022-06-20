/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_b2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:32:52 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:32:55 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upd(t_par *control, int lena, int lenb)
{
	int	fin;

	if (control->score > lena / 2)
		control->score = -(lena - control->score);
	if (control->sc_b > lenb / 2)
		control->sc_b = -(lenb - control->sc_b);
	if (control->score * control->sc_b >= 0)
		fin = maximus(ft_abs(control->score), ft_abs(control->sc_b));
	else
		fin = ft_abs(control->score) + ft_abs(control->sc_b);
	if (control->final_score > fin)
	{
		control->final_score = ft_abs(fin);
		control->m_a = control->score;
		control->m_b = control->sc_b;
	}
}

static int	try_2p2(t_list *lst_a, t_list *lst_b)
{
	while (lst_a)
	{
		if ((int)lst_b->content < (int)lst_a->content)
			return (1);
		lst_a = lst_a->next;
	}
	return (0);
}

int	try_2(t_list *lst_a, t_list *lst_b, t_par *control, t_list *before)
{
	if ((int)lst_a->content < (int)lst_b->content)
	{
		if (try_2p2(lst_a, lst_b) == 0
			&& (int)lst_b->content > (int)before->content)
			if ((int)lst_a->content == control->min)
				return (1);
		return (0);
	}
	if ((int)lst_a->content > (int)lst_b->content)
	{
		if ((int)lst_a->content == control->min)
			return (1);
		if (before)
		{
			if ((int)lst_b->content > (int)before->content)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

t_list	*sh_before(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
