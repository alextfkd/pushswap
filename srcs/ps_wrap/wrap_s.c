/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/14 22:01:03 by tkatsuma         ###   ########.fr       */
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
		new_ops = create_cdlst_node(SA);
		insert_nil_next(&((*stacks)->stack_ops), new_ops);
		(*stacks)->op_count++;
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
		new_ops = create_cdlst_node(SB);
		insert_nil_next(&((*stacks)->stack_ops), new_ops);
		(*stacks)->op_count++;
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
		insert_nil_next(&((*stacks)->stack_ops), new_ops);
	}
	return (res);
}
