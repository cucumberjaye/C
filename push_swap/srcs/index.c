/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:31:35 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:31:37 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sorted(t_list *lst)
{
	t_list	*helper;
	t_list	*first;
	long	swap;

	first = lst;
	while (lst->next)
	{
		helper = lst->next;
		while (helper)
		{
			if ((int)lst->content > (int)helper->content)
			{
				swap = (int)lst->content;
				lst->content = helper->content;
				helper->content = (void *)swap;
			}
			helper = helper->next;
		}
		lst = lst->next;
	}
	return (first);
}

void	lstclear(t_list **lst)
{
	t_list	*helper;

	while (*lst)
	{
		helper = *lst;
		*lst = (*lst)->next;
		free(helper);
		helper = NULL;
	}
	*lst = NULL;
}

int	median(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	if (len % 2 == 0)
		return (len / 2);
	return (len / 2 + 1);
}

void	indx(t_list *lst, t_par *control)
{
	t_list	*new;
	t_list	*first;
	int		len;

	new = NULL;
	first = lst;
	while (first)
	{
		ft_lstadd_back(&new, ft_lstnew(first->content));
		first = first->next;
	}
	new = sorted(new);
	len = median(new);
	first = new;
	while (--len)
		new = new->next;
	control->med = (int)new->content;
	lstclear(&first);
}
