/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:21:38 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/24 20:27:29 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	w_pa(t_psstacks **stacks)
{
	int	res;

	res = push_to_a_stack(stacks);
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}

int	w_pb(t_psstacks **stacks)
{
	int	res;

	res = push_to_b_stack(stacks);
	if (res == 0)
		(*stacks)->op_count++;
	return (res);
}
