/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:35:07 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/26 14:35:11 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort_b(t_list *lst_a, t_list *lst_b)
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

int	mv_lst(t_list **lst_a, t_list **lst_b, char *str)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		ra_or_rb(lst_a);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra_or_rrb(lst_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		ra_or_rb(lst_b);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rra_or_rrb(lst_b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr_b(lst_a, lst_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr_b(lst_a, lst_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa_or_pb(lst_a, lst_b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pa_or_pb(lst_b, lst_a);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		*lst_a = sa_or_sb(*lst_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		*lst_b = sa_or_sb(*lst_b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(lst_a, lst_b);
	else
		return (1);
	return (0);
}

char	**half(t_list **lst_a, t_list **lst_b, char **str, char **argv)
{
	*lst_a = NULL;
	*lst_b = NULL;
	*str = NULL;
	++argv;
	return (argv);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*str;

	argv = half(&lst_a, &lst_b, &str, argv);
	pars(argc, argv, &lst_a);
	if (errors(lst_a) == 1)
		exit (0);
	list_of_int(&lst_a);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (mv_lst(&lst_a, &lst_b, str) == 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (is_sort_b(lst_a, lst_b) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}
