/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/24 20:39:35 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	w_rra(t_psstacks **stacks)
{
	int	res;

	res = rotate_forward(&((*stacks)->stack_a));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}

int	w_rrb(t_psstacks **stacks)
{
	int	res;

	res = rotate_forward(&((*stacks)->stack_b));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}

int	w_rrr(t_psstacks **stacks)
{
	int	res;

	res = 0;
	res += rotate_forward(&((*stacks)->stack_a));
	res += rotate_forward(&((*stacks)->stack_b));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}
