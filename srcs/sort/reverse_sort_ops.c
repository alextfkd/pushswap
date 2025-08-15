/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:07:56 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/15 16:08:21 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_reverse_sort_ops(t_psstacks **stacks, t_cdlist *ops)
{
	if (ops->content->value == PA)
		w_pb(stacks);
	else if (ops->content->value == PB)
		w_pa(stacks);
	else if (ops->content->value == SA)
		w_sa(stacks);
	else if (ops->content->value == SB)
		w_sb(stacks);
	else if (ops->content->value == SS)
		w_ss(stacks);
	else if (ops->content->value == RA)
		w_rra(stacks);
	else if (ops->content->value == RB)
		w_rrb(stacks);
	else if (ops->content->value == RR)
		w_rrr(stacks);
	else if (ops->content->value == RRA)
		w_ra(stacks);
	else if (ops->content->value == RRB)
		w_rb(stacks);
	else if (ops->content->value == RRR)
		w_rr(stacks);
	else
		ft_perror(FT_EOPS);
}

void	reverse_sorted(t_psstacks **stacks)
{
	t_cdlist	*tmp;

	tmp = (*stacks)->stack_ops->next;
	while (tmp->content != NULL)
	{
		_reverse_sort_ops(stacks, tmp);
		tmp = tmp->next;
	}
}
