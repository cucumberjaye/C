/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:24:44 by cjaye             #+#    #+#             */
/*   Updated: 2022/01/25 14:24:45 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static char	*sm_strdup(char *src, int l)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (l + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < l)
	{
		new[i] = src[i];
		++i;
	}
	new[l] = '\0';
	return (new);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static char	*space(char *str)
{
	while (*str)
	{
		if (is_space(*str) == 1)
			++str;
		else
			break ;
	}
	return (str);
}

void	pars(int argc, char **argv, t_list **new_lst)
{
	int		i;

	i = 0;
	while (--argc > 0)
	{
		*argv = space(*argv);
		while (1)
		{
			if (is_space(**argv) == 1 || **argv == '\0')
			{
				ft_lstadd_back(new_lst, ft_lstnew(sm_strdup(*argv - i, i)));
				i = 0;
				*argv = space(*argv);
				if (**argv == '\0')
					break ;
			}
			else
			{
				++(*argv);
				++i;
			}
		}
		++argv;
	}
}

void	list_of_int(t_list **lst)
{
	t_list	*helper;
	t_list	*goal;

	goal = NULL;
	while (*lst)
	{
		ft_lstadd_back(&goal, ft_lstnew((void *)ft_atoi((*lst)->content)));
		helper = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = helper;
	}
	*lst = goal;
}
