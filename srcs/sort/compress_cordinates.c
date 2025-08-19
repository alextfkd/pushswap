/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_cordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:33:39 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 07:24:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplication(t_psstacks **stacks)
{
	t_cdlist	*n0;
	t_cdlist	*n1;

	if (cdlst_len((*stacks)->stack_a) == 1)
		return (0);
	n0 = cdlst_find_head((*stacks)->stack_a);
	n1 = n0->next;
	while (n1->content != NULL)
	{
		if (n0->content->value == n1->content->value)
			return (1);
		n0 = n1;
		n1 = n1->next;
	}
	return (0);
}

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
	if (check_duplication(stacks) == 1)
	{
		delete_cdlst(&((*stacks)->stack_ops));
		free((*stacks)->a_ops);
		free((*stacks)->b_ops);
		return (1);
	}
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
