/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:24:31 by cjaye             #+#    #+#             */
/*   Updated: 2022/01/25 14:24:33 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	duplicates(t_list *lst)
{
	t_list	*helper;

	while (lst->next)
	{
		helper = lst->next;
		while (helper)
		{
			if (ft_strncmp(lst->content, helper->content, 11) == 0)
				return (1);
			helper = helper->next;
		}
		lst = lst->next;
	}
	return (0);
}

static int	check(char str, int s, int znak)
{
	if (znak == 1 && - s > 214748364)
		return (1);
	if (znak == 1 && - s == 214748364 && str > '7')
		return (1);
	if (s < -214748364)
		return (1);
	if (s == -214748364 && str > '8')
		return (1);
	return (0);
}

static int	is_integer(t_list *lst)
{
	int	i;
	int	s;
	int	znak;

	while (lst)
	{	
		znak = 1;
		i = -1;
		s = 0;
		while (((char *)lst->content)[++i])
		{	
			if (i == 0 && ((char *)lst->content)[i] == '-')
			{
				znak = -1;
				++i;
			}
			if (ft_isdigit(((char *)lst->content)[i]) == 0)
				return (1);
			if (check(((char *)lst->content)[i], s, znak) == 1)
				return (1);
			s = 10 * s - (((char *)lst->content)[i] - '0');
		}
		lst = lst->next;
	}
	return (0);
}

int	errors(t_list *lst)
{
	if (duplicates(lst) == 1 || is_integer(lst) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
