/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:07:43 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/24 21:23:01 by tkatsuma         ###   ########.fr       */
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

int	if_stack_a_sorted(t_psstacks *stacks)
{
	t_cdlist	*stack_a;

	stack_a = cdlst_find_nil(stacks->stack_a);
	stack_a = stack_a->next;
	if (stack_a->content == NULL)
		return (1);
	while (stack_a->next->content != NULL)
	{
		if (stack_a->content->value >= stack_a->next->content->value)
			return (0);
		stack_a = stack_a->next;
	}
	ft_printf("STACK A is SORTED!\n");
	return (1);
}

int	if_stack_b_sorted(t_psstacks *stacks)
{
	t_cdlist	*stack_b;

	stack_b = cdlst_find_nil(stacks->stack_b);
	stack_b = stack_b->next;
	if (stack_b->content == NULL)
		return (1);
	while (stack_b->next->content != NULL)
	{
		if (stack_b->content->value <= stack_b->next->content->value)
			return (0);
		stack_b = stack_b->next;
	}
	ft_printf("STACK B is SORTED!\n");
	return (1);
}

int	if_stacks_sorted(t_psstacks *stacks)
{
	int	res;

	res = 0;
	res += if_stack_a_sorted(stacks);
	res += if_stack_b_sorted(stacks);
	if (res == 2)
		return (1);
	return (0);
}
