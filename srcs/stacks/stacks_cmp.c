/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:24:32 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 06:40:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_stacks(t_psstacks *stacks_1, t_psstacks *stacks_2)
{
	if (stacks_1 == NULL || stacks_2 == NULL)
		return (0);
	if (cmp_cdlst(stacks_1->stack_a, stacks_2->stack_a) == 0)
		return (0);
	if (cmp_cdlst(stacks_1->stack_b, stacks_2->stack_b) == 0)
		return (0);
	return (1);
}
