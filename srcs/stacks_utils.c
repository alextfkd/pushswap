/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:07:43 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/24 19:08:42 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_print_stacks(t_cdlist *stack_a, t_cdlist *stack_b)
{
	print_cdlst(stack_a, STACK_A);
	ft_printf("| ");
	print_cdlst(stack_b, STACK_B);
	ft_printf("\n");
}

void	print_stacks(t_psstacks *stacks)
{
	_print_stacks(stacks->stack_a, stacks->stack_b);
}
