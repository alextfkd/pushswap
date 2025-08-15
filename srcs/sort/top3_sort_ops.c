/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top3_sort_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:00:03 by marvin            #+#    #+#             */
/*   Updated: 2025/08/15 19:22:40 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*_desc_top3_sort_ops(int top3_status)
{
	char	*ops;

	if (top3_status == ORDER_123)
		ops = ft_strdup("sRsrs");
	else if (top3_status == ORDER_132)
		ops = ft_strdup("sRsr");
	else if (top3_status == ORDER_321)
		ops = ft_strdup("");
	else if (top3_status == ORDER_231)
		ops = ft_strdup("s");
	else if (top3_status == ORDER_213)
		ops = ft_strdup("Rsrs");
	else if (top3_status == ORDER_312)
		ops = ft_strdup("Rsr");
	else if (top3_status == ORDER_21)
		ops = ft_strdup("");
	else if (top3_status == ORDER_12)
		ops = ft_strdup("s");
	else if (top3_status == ORDER_1)
		ops = ft_strdup("");
	else if (top3_status == ORDER_0)
		ops = ft_strdup("");
	else
		ops = NULL;
	return (ops);
}

static char	*_asc_top3_sort_ops(int top3_status)
{
	char	*ops;

	if (top3_status == ORDER_123)
		ops = ft_strdup("");
	else if (top3_status == ORDER_132)
		ops = ft_strdup("Rsr");
	else if (top3_status == ORDER_321)
		ops = ft_strdup("sRsrs");
	else if (top3_status == ORDER_231)
		ops = ft_strdup("Rsrs");
	else if (top3_status == ORDER_213)
		ops = ft_strdup("s");
	else if (top3_status == ORDER_312)
		ops = ft_strdup("sRsr");
	else if (top3_status == ORDER_21)
		ops = ft_strdup("s");
	else if (top3_status == ORDER_12)
		ops = ft_strdup("");
	else if (top3_status == ORDER_1)
		ops = ft_strdup("");
	else if (top3_status == ORDER_0)
		ops = ft_strdup("");
	else
		ops = NULL;
	return (ops);
}

int	sort_top3_stacks(t_psstacks **stacks, int a_dir, int b_dir)
{
	int		idxa;
	int		idxb;
	char	*a_ops;
	char	*b_ops;

	idxa = stack_top3_status((*stacks)->stack_a);
	idxb = stack_top3_status((*stacks)->stack_b);
	if (a_dir == SORT_ASC)
		a_ops = _asc_top3_sort_ops(idxa);
	else if (a_dir == SORT_DESC)
		a_ops = _desc_top3_sort_ops(idxa);
	else
		a_ops = ft_strdup("");
	if (b_dir == SORT_ASC)
		b_ops = _asc_top3_sort_ops(idxb);
	else if (b_dir == SORT_DESC)
		b_ops = _desc_top3_sort_ops(idxb);
	else
		b_ops = ft_strdup("");
	if (a_ops == NULL || b_ops == NULL || idxa == -1 || idxb == -1)
		return (-1);
	(*stacks)->a_ops = a_ops;
	(*stacks)->b_ops = b_ops;
	return (0);
}

int	sort_stack_a_top3_desc(t_psstacks **stacks)
{
	int		top3_status;
	char	*ops;

	top3_status = stack_top3_status((*stacks)->stack_a);
	if (top3_status == -1)
		return (-1);
	ops = _desc_top3_sort_ops(top3_status);
	(*stacks)->a_ops = ops;
	return (0);
}

int	sort_stack_a_top3_asc(t_psstacks **stacks)
{
	int		top3_status;
	char	*ops;

	top3_status = stack_top3_status((*stacks)->stack_a);
	if (top3_status == -1)
		return (-1);
	ops = _asc_top3_sort_ops(top3_status);
	(*stacks)->a_ops = ops;
	return (0);
}
