/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/18 00:06:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	w_sa(t_psstacks **stacks)
{
	int			res;
	t_cdlist	*new_ops;

	res = swap_forward(&((*stacks)->stack_a));
	if (res == 0)
	{
		(*stacks)->op_count++;
		new_ops = create_cdlst_node(SA);
		if (new_ops == NULL)
			return (1);
		res += insert_nil_next(&((*stacks)->stack_ops), new_ops);
	}
	return (res);
}

int	w_sb(t_psstacks **stacks)
{
	int			res;
	t_cdlist	*new_ops;

	res = swap_forward(&((*stacks)->stack_b));
	if (res == 0)
	{
		(*stacks)->op_count++;
		new_ops = create_cdlst_node(SB);
		if (new_ops == NULL)
			return (1);
		res += insert_nil_next(&((*stacks)->stack_ops), new_ops);
	}
	return (res);
}

int	w_ss(t_psstacks **stacks)
{
	int			res;
	t_cdlist	*new_ops;

	res = 0;
	res += swap_forward(&((*stacks)->stack_a));
	res += swap_forward(&((*stacks)->stack_b));
	if (res == 0)
	{
		(*stacks)->op_count++;
		new_ops = create_cdlst_node(SS);
		if (new_ops == NULL)
			return (1);
		res += insert_nil_next(&((*stacks)->stack_ops), new_ops);
	}
	return (res);
}
