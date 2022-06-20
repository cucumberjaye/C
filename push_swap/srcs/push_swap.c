/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:31:53 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:31:55 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	win(t_list **lst_a, t_list *lst_b, int flag)
{
	if (flag == 1)
	{
		while (is_sort(*lst_a, lst_b) != 1)
		{
			ra_or_rb(lst_a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (is_sort(*lst_a, lst_b) != 1)
		{
			rra_or_rrb(lst_a);
			write(1, "rra\n", 4);
		}
	}
}

t_par	*cr_control(void)
{
	t_par	*new;

	new = (t_par *)malloc(sizeof(t_par));
	if (!new)
		return (NULL);
	new->elems = 0;
	new->med = 0;
	new->min = 0;
	new->lenght = 0;
	new->final_score = 10000;
	new->m_b = 0;
	new->score = 0;
	new->m_a = 0;
	new->sc_b = 0;
	return (new);
}	

int	main(int argc, char **argv)
{
	t_par	*control;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc == 1)
		exit(0);
	control = cr_control();
	++(argv);
	pars(argc, argv, &lst_a);
	if (errors(lst_a) == 1)
		exit(0);
	list_of_int(&lst_a);
	indx(lst_a, control);
	algorithm(&lst_a, lst_b, control);
	exit(0);
}
