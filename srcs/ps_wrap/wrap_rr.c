/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/14 22:00:48 by tkatsuma         ###   ########.fr       */
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
		new_ops = create_cdlst_node(RRA);
		insert_nil_next(&((*stacks)->stack_ops), new_ops);
		(*stacks)->op_count++;
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
		new_ops = create_cdlst_node(RRB);
		insert_nil_next(&((*stacks)->stack_ops), new_ops);
		(*stacks)->op_count++;
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
		new_ops = create_cdlst_node(RRR);
		insert_nil_next(&((*stacks)->stack_ops), new_ops);
		(*stacks)->op_count++;
	}
	return (res);
}
