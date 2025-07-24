/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/24 20:34:29 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	w_sa(t_psstacks **stacks)
{
	int	res;

	res = swap_forward(&((*stacks)->stack_a));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}

int	w_sb(t_psstacks **stacks)
{
	int	res;

	res = swap_forward(&((*stacks)->stack_b));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}

int	w_ss(t_psstacks **stacks)
{
	int	res;

	res = 0;
	res += swap_forward(&((*stacks)->stack_a));
	res += swap_forward(&((*stacks)->stack_b));
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}
