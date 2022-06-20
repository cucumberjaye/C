/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:33:23 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:33:26 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sa_or_sb(t_list *lst)
{
	t_list	*helper;

	if (!lst || !lst->next)
		return (NULL);
	helper = lst->next;
	lst->next = helper->next;
	helper->next = lst;
	return (helper);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	*lst_a = sa_or_sb(*lst_a);
	*lst_b = sa_or_sb(*lst_b);
}

void	pa_or_pb(t_list **lst_1, t_list **lst_2)
{
	t_list	*helper;

	helper = *lst_2;
	*lst_2 = (*lst_2)->next;
	helper->next = *lst_1;
	*lst_1 = helper;
}

void	ra_or_rb(t_list **lst)
{
	t_list	*helper;
	t_list	*first;

	if (!(*lst)->next)
		return ;
	helper = *lst;
	first = (*lst)->next;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = helper;
	helper->next = NULL;
	*lst = first;
}

void	rra_or_rrb(t_list **lst)
{
	t_list	*helper;
	t_list	*last;

	if (!(*lst)->next)
		return ;
	helper = *lst;
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	last = (*lst)->next;
	last->next = helper;
	(*lst)->next = NULL;
	*lst = last;
}
