/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 03:32:33 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 03:33:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_aops(t_psstacks **stacks, char op)
{
	if (op == 'r')
		w_ra(stacks);
	else if (op == 'R')
		w_rra(stacks);
	else if (op == 's')
		w_sa(stacks);
	else
		return (1);
	return (0);
}

static int	do_bops(t_psstacks **stacks, char op)
{
	if (op == 'r')
		w_rb(stacks);
	else if (op == 'R')
		w_rrb(stacks);
	else if (op == 's')
		w_sb(stacks);
	else
		return (1);
	return (0);
}

static int	do_wops(t_psstacks **stacks, char op)
{
	if (op == 'r')
		w_rr(stacks);
	else if (op == 'R')
		w_rrr(stacks);
	else if (op == 's')
		w_ss(stacks);
	else
		return (1);
	return (0);
}

int	do_ops(t_psstacks **stacks)
{
	char	*a_ptr;
	char	*b_ptr;
	int		status;

	status = 0;
	a_ptr = (*stacks)->a_ops;
	b_ptr = (*stacks)->b_ops;
	while (a_ptr != NULL && *a_ptr != '\0')
	{
		if (b_ptr != NULL && *a_ptr == *b_ptr)
		{
			status += do_wops(stacks, *a_ptr);
			b_ptr++;
		}
		else
			status += do_aops(stacks, *a_ptr);
		a_ptr++;
	}
	while (b_ptr != NULL && *b_ptr != '\0')
		status += do_bops(stacks, *b_ptr++);
	return (status);
}
