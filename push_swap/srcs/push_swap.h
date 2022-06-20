/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:32:12 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/04 14:32:14 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../liba/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_srt
{
	t_list	*first;
	int		max;
	int		now;
	int		flag;
}				t_srt;

typedef struct s_par
{
	int		lenght;
	int		score;
	int		sc_b;
	int		min;
	int		elems;
	int		med;
	int		final_score;
	int		m_b;
	int		m_a;
}			t_par;

int		errors(t_list *lst);
void	pars(int argc, char **argv, t_list **new_lst);
void	list_of_int(t_list **lst);
t_list	*sa_or_sb(t_list *lst);
void	ss(t_list **lst_a, t_list **lst_b);
void	pa_or_pb(t_list **lst_1, t_list **lst_2);
void	ra_or_rb(t_list **lst);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra_or_rrb(t_list **lst);
void	rrr(t_list **lst_a, t_list **lst_b);
void	indx(t_list *lst, t_par *control);
void	algorithm(t_list **lst_a, t_list *lst_b, t_par *control);
int		median(t_list *lst);
int		search_sort(t_list *lst, t_list **start);
t_list	*search_indx(t_list *lst, int indx, int max);
t_list	*first_step(t_list *lst, int *max, t_list **start);
void	lstclear(t_list **lst);
void	if_score_b(t_list **lst_a, t_list **lst_b,
			t_par *control, t_list **start);
int		score_b(t_list *lst_a, t_list *lst_b, t_list *start, t_par *control);
void	if_score_a(t_list **lst_a, t_list **lst_b,
			t_par *control, t_list **start);
int		score_a(t_list *lst_a, t_par *control, t_list *start);
t_par	*cr_control(void);
int		len_lst(t_list *lst_b);
int		maximus(int a, int b);
int		ft_abs(int num);
t_par	*free_con(t_par *control);
void	upd(t_par *control, int lena, int lenb);
int		try_2(t_list *lst_a, t_list *lst_b, t_par *control, t_list *before);
t_list	*sh_before(t_list *lst);
void	win(t_list **lst_a, t_list *lst_b, int flag);
int		is_sort(t_list *lst_a, t_list *lst_b);
int		roll(t_list *lst_a, t_list *lst_b);
void	rr_b(t_list **lst_a, t_list **lst_b);
void	rrr_b(t_list **lst_a, t_list **lst_b);

#endif
