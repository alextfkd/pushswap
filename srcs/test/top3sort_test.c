/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top3sort_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 04:11:45 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 05:18:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_vsort_top3(t_psstacks *sorted, int *arr, int len, int print)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pbn(&stack, 3);
	if (print)
	{
		print_stacks(stack);
		ft_printf("Current status -> [%d]\n", stack_top3_status(stack->stack_a));
	}
	vsort_top3_stacks(&stack);
	do_ops(&stack);
	if (print)
		print_stacks(stack);
	if (cmp_stacks(sorted, stack) == 0)
	{
		free_stacks(&stack);
		ft_printf("[FAILED]\n");
		return (1);
	}
	ft_printf("[PASSED]\n");
	return (0);
}

int	test_msort_top3(t_psstacks *sorted, int *arr, int len, int print)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pbn(&stack, 3);
	if (print)
	{
		print_stacks(stack);
		ft_printf("Current status -> [%d]\n", stack_top3_status(stack->stack_a));
	}
	msort_top3_stacks(&stack);
	do_ops(&stack);
	if (print)
		print_stacks(stack);
	if (cmp_stacks(sorted, stack) == 0)
	{
		free_stacks(&stack);
		ft_printf("[FAILED]\n");
		return (1);
	}
	ft_printf("[PASSED]\n");
	return (0);
}

int	test_asort_top3(t_psstacks *sorted, int *arr, int len, int print)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pbn(&stack, 3);
	if (print)
	{
		print_stacks(stack);
		ft_printf("Current status -> [%d]\n", stack_top3_status(stack->stack_a));
	}
	asort_top3_stacks(&stack);
	do_ops(&stack);
	if (print)
		print_stacks(stack);
	if (cmp_stacks(sorted, stack) == 0)
	{
		free_stacks(&stack);
		ft_printf("[FAILED]\n");
		return (1);
	}
	ft_printf("[PASSED]\n");
	return (0);
}

int	test_dsort_top3(t_psstacks *sorted, int *arr, int len, int print)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pbn(&stack, 3);
	if (print)
	{
		print_stacks(stack);
		ft_printf("Current status -> [%d]\n", stack_top3_status(stack->stack_a));
	}
	dsort_top3_stacks(&stack);
	do_ops(&stack);
	if (print)
		print_stacks(stack);
	if (cmp_stacks(sorted, stack) == 0)
	{
		ft_printf("[FAILED]\n");
		free_stacks(&stack);
		return (1);
	}
	ft_printf("[PASSED]\n");
	return (0);
}

