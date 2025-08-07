/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/07 08:34:52 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	w_ra(t_psstacks **stacks)
{
	int	res;

	res = rotate_forward(&((*stacks)->stack_a));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}

int	w_rb(t_psstacks **stacks)
{
	int	res;

	res = rotate_forward(&((*stacks)->stack_b));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}

int	w_rr(t_psstacks **stacks)
{
	int	res;

	res = 0;
	res += rotate_forward(&((*stacks)->stack_a));
	res += rotate_forward(&((*stacks)->stack_b));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}
