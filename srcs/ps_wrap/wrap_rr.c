/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/18 00:05:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	w_rra(t_psstacks **stacks)
{
	int			res;
	t_cdlist	*new_ops;

	res = rotate_backward(&((*stacks)->stack_a));
	if (res == 0)
	{
		(*stacks)->op_count++;
		new_ops = create_cdlst_node(RRA);
		if (new_ops == NULL)
			return (1);
		res += insert_nil_next(&((*stacks)->stack_ops), new_ops);
	}
	return (res);
}

int	w_rrb(t_psstacks **stacks)
{
	int			res;
	t_cdlist	*new_ops;

	res = rotate_backward(&((*stacks)->stack_b));
	if (res == 0)
	{
		(*stacks)->op_count++;
		new_ops = create_cdlst_node(RRB);
		if (new_ops == NULL)
			return (1);
		res += insert_nil_next(&((*stacks)->stack_ops), new_ops);
	}
	return (res);
}

int	w_rrr(t_psstacks **stacks)
{
	int			res;
	t_cdlist	*new_ops;

	res = 0;
	res += rotate_backward(&((*stacks)->stack_a));
	res += rotate_backward(&((*stacks)->stack_b));
	if (res == 0)
	{
		(*stacks)->op_count++;
		new_ops = create_cdlst_node(RRR);
		if (new_ops == NULL)
			return (1);
		res += insert_nil_next(&((*stacks)->stack_ops), new_ops);
	}
	return (res);
}
