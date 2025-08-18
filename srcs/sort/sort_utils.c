/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:11:03 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/18 00:15:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	presort_stacks(t_psstacks **stacks)
{
	int	i;
	int	status;
	int	arrlen;

	i = 0;
	status = 0;
	arrlen = cdlst_len((*stacks)->stack_a) + cdlst_len((*stacks)->stack_b);
	while (i <= arrlen / 6)
	{
		w_pbn(stacks, 3);
		status += asort_top3_stacks(stacks);
		if (status == -1)
		{
			free_stacks(stacks);
			exit(1);
		}
		do_ops(stacks);
		w_pbn(stacks, 3);
		i++;
	}
	return (0);
}

int	push_all_to_stack_a(t_psstacks **stacks)
{
	int	status;

	status = 0;
	while (cdlst_len((*stacks)->stack_b) > 0)
		status += w_pa(stacks);
	return (status);
}

int	push_all_to_stack_b(t_psstacks **stacks)
{
	int	status;

	status = 0;
	while (cdlst_len((*stacks)->stack_a) > 0)
		status += w_pb(stacks);
	return (status);
}

int	set_rank_for_sorted(t_psstacks **stacks)
{
	int			i;
	t_cdlist	*tmp;

	i = 0;
	tmp = cdlst_find_head((*stacks)->stack_a);
	while (tmp->content != NULL)
	{
		tmp->content->value = i++;
		tmp = tmp->next;
	}
	return (0);
}
