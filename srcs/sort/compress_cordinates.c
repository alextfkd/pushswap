/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_cordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:33:39 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 02:02:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compress_cordinates(t_psstacks **stacks)
{
	int	n;
	int	status;

	status = 0;
	n = cdlst_len((*stacks)->stack_a);
	if (n < 0)
		return (1);
	status += push_all_to_stack_a(stacks);
	status += naive_radix_sort(stacks, n);
	status += set_rank_for_sorted(stacks);
	reverse_sorted(stacks);
	status += push_all_to_stack_a(stacks);
	delete_cdlst(&((*stacks)->stack_ops));
	free((*stacks)->a_ops);
	free((*stacks)->b_ops);
	(*stacks)->stack_ops = ft_cdlstinit();
	(*stacks)->op_count = 0;
	return (status);
}
