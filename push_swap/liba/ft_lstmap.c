/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:59:16 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/22 12:38:47 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*helper;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		helper = ft_lstnew(f(lst->content));
		if (!helper)
		{	
			ft_lstclear(&helper, del);
			break ;
		}
		ft_lstadd_back(&new, helper);
		lst = lst->next;
	}
	return (new);
}
