/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:33:30 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:33:32 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **lst_a, t_list **lst_b)
{
	if (!(*lst_a) || !(*lst_b))
		return ;
	ra_or_rb(lst_a);
	ra_or_rb(lst_b);
	write(1, "rr\n", 3);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	if (!(*lst_a) || !(*lst_b))
		return ;
	rra_or_rrb(lst_a);
	rra_or_rrb(lst_b);
	write(1, "rrr\n", 4);
}
