/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:35:24 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/26 14:35:26 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_b(t_list **lst_a, t_list **lst_b)
{
	if (!(*lst_a) || !(*lst_b))
		return ;
	ra_or_rb(lst_a);
	ra_or_rb(lst_b);
}

void	rrr_b(t_list **lst_a, t_list **lst_b)
{
	if (!(*lst_a) || !(*lst_b))
		return ;
	rra_or_rrb(lst_a);
	rra_or_rrb(lst_b);
}
