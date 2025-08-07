/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:21:38 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/04 11:02:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	w_pa(t_psstacks **stacks)
{
	int	res;

	res = push_to_a_stack(stacks);
	if (res == 1)
		(*stacks)->op_count++;
	return (res);
}

int	w_pb(t_psstacks **stacks)
{
	int	res;

	res = push_to_b_stack(stacks);
	if (res == 1)
		(*stacks)->op_count++;
	return (res);
}

int	w_pan(t_psstacks **stacks, int n)
{
	int	res;

	res = 0;
	while (n > 0)
	{
		res += w_pa(stacks);
		n--;
	}
	return (res);
}

int	w_pbn(t_psstacks **stacks, int n)
{
	int	res;

	res = 0;
	while (n > 0)
	{
		res += w_pb(stacks);
		n--;
	}
	return (res);
}
