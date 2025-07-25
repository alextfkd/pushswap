/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top3_sort_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:00:03 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 06:27:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*_desc_top3_sort_ops(int top3_status)
{
	char	*ops;

	if (top3_status == ORDER_123)
		ops = ft_strdup("srsRs");
	else if (top3_status == ORDER_132)
		ops = ft_strdup("srsR");
	else if (top3_status == ORDER_321)
		ops = ft_strdup("");
	else if (top3_status == ORDER_231)
		ops = ft_strdup("s");
	else if (top3_status == ORDER_213)
		ops = ft_strdup("rsRs");
	else if (top3_status == ORDER_312)
		ops = ft_strdup("rsR");
	else
		ops = ft_strdup("");
	return (ops);
}

static char	*_asc_top3_sort_ops(int top3_status)
{
	char	*ops;

	if (top3_status == ORDER_123)
		ops = ft_strdup("");
	else if (top3_status == ORDER_132)
		ops = ft_strdup("rsR");
	else if (top3_status == ORDER_321)
		ops = ft_strdup("srsRs");
	else if (top3_status == ORDER_231)
		ops = ft_strdup("rsRs");
	else if (top3_status == ORDER_213)
		ops = ft_strdup("s");
	else if (top3_status == ORDER_312)
		ops = ft_strdup("srsR");
	else
		ops = ft_strdup("");
	return (ops);
}

int	sort_top3_stacks(t_psstacks **stacks, int a_dir, int b_dir)
{
	int 	top3_status_a;
	int 	top3_status_b;
	char	*a_ops;
	char	*b_ops;
	
	top3_status_a = stack_top3_status((*stacks)->stack_a);
	top3_status_b = stack_top3_status((*stacks)->stack_b);
	if (a_dir == SORT_ASC)
		a_ops = _asc_top3_sort_ops(top3_status_a);
	else if (a_dir == SORT_DESC)
		a_ops = _desc_top3_sort_ops(top3_status_a);
	else
		a_ops = ft_strdup("");
	if (b_dir == SORT_ASC)
		b_ops = _asc_top3_sort_ops(top3_status_b);
	else if (b_dir == SORT_DESC)
		b_ops = _desc_top3_sort_ops(top3_status_b);
	else
		b_ops = ft_strdup("");
	if (a_ops == NULL || b_ops == NULL)
		(*stacks)->status = 1;
	(*stacks)->a_ops = a_ops;
	(*stacks)->b_ops = b_ops;
	return (0);
}

int	sort_stack_a_top3_desc(t_psstacks ** stacks)
{
	int 	top3_status;
	char	*ops;

	top3_status = stack_top3_status((*stacks)->stack_a);
	ops = _desc_top3_sort_ops(top3_status);
	(*stacks)->a_ops = ops;
	return (0);
}

int	sort_stack_a_top3_asc(t_psstacks ** stacks)
{
	int 	top3_status;
	char	*ops;

	top3_status = stack_top3_status((*stacks)->stack_a);
	ops = _asc_top3_sort_ops(top3_status);
	(*stacks)->a_ops = ops;
	return (0);
}
