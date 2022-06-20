/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:02:51 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/21 17:57:25 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*helper;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	helper = *lst;
	while (helper->next)
		helper = helper->next;
	helper->next = new;
	helper = 0;
}
