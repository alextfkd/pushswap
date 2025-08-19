/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sort_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:07:23 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/19 08:55:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_print_sort_ops(t_cdlist *ops)
{
	if (ops->content->value == PA)
		ft_printf("pa\n");
	else if (ops->content->value == PB)
		ft_printf("pb\n");
	else if (ops->content->value == SA)
		ft_printf("sa\n");
	else if (ops->content->value == SB)
		ft_printf("sb\n");
	else if (ops->content->value == SS)
		ft_printf("ss\n");
	else if (ops->content->value == RA)
		ft_printf("ra\n");
	else if (ops->content->value == RB)
		ft_printf("rb\n");
	else if (ops->content->value == RR)
		ft_printf("rr\n");
	else if (ops->content->value == RRA)
		ft_printf("rra\n");
	else if (ops->content->value == RRB)
		ft_printf("rrb\n");
	else if (ops->content->value == RRR)
		ft_printf("rrr\n");
	else
		ft_perror(FT_EOPS);
}

int	print_sort_ops(t_psstacks **stacks)
{
	t_cdlist	*tmp;

	if (stacks == NULL || *stacks == NULL)
		return (1);
	if ((*stacks)->stack_ops == NULL)
		return (1);
	tmp = cdlst_find_tail((*stacks)->stack_ops);
	while (tmp->content != NULL)
	{
		_print_sort_ops(tmp);
		tmp = tmp->prev;
	}
	return (0);
}
