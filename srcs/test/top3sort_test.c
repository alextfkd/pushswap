/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top3sort_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 04:11:45 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 08:21:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_vsort_top2(t_psstacks *sorted, int *arr, int len, int print)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pbn(&stack, 2);
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
	free_stacks(&stack);
	ft_printf("[PASSED]\n");
	return (0);
}

int	test_msort_top2(t_psstacks *sorted, int *arr, int len, int print)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pbn(&stack, 2);
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
	free_stacks(&stack);
	ft_printf("[PASSED]\n");
	return (0);
}

int	test_asort_top2(t_psstacks *sorted, int *arr, int len, int print)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pbn(&stack, 2);
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
	free_stacks(&stack);
	ft_printf("[PASSED]\n");
	return (0);
}

int	test_dsort_top2(t_psstacks *sorted, int *arr, int len, int print)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pbn(&stack, 2);
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
	free_stacks(&stack);
	ft_printf("[PASSED]\n");
	return (0);
}


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
	free_stacks(&stack);
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
	free_stacks(&stack);
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
	free_stacks(&stack);
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
	free_stacks(&stack);
	ft_printf("[PASSED]\n");
	return (0);
}

int	top3_sort_test(void)
{
	t_psstacks *stack_vsorted;
	t_psstacks *stack_msorted;
	t_psstacks *stack_asorted;
	t_psstacks *stack_dsorted;
	int v_sorted[6] = {3, 2, 1, 4, 5, 6};
	int m_sorted[6] = {1, 2, 3, 6, 5, 4};
	int a_sorted[6] = {1, 2, 3, 4, 5, 6};
	int d_sorted[6] = {3, 2, 1, 6, 5, 4};
	stack_vsorted = init_stacks_from_array(v_sorted, 6);
	stack_msorted = init_stacks_from_array(m_sorted, 6);
	stack_asorted = init_stacks_from_array(a_sorted, 6);
	stack_dsorted = init_stacks_from_array(d_sorted, 6);
	w_pbn(&stack_vsorted, 3);
	w_pbn(&stack_msorted, 3);
	w_pbn(&stack_asorted, 3);
	w_pbn(&stack_dsorted, 3);
	int	arr01[6] = {1, 2, 3, 4, 5, 6};
	int	arr02[6] = {1, 3, 2, 4, 5, 6};
	int	arr03[6] = {2, 1, 3, 4, 5, 6};
	int	arr04[6] = {2, 3, 1, 4, 5, 6};
	int	arr05[6] = {3, 1, 2, 4, 5, 6};
	int	arr06[6] = {3, 2, 1, 4, 5, 6};
	int	arr11[6] = {1, 2, 3, 4, 5, 6};
	int	arr12[6] = {1, 2, 3, 4, 6, 5};
	int	arr13[6] = {1, 2, 3, 5, 4, 6};
	int	arr14[6] = {1, 2, 3, 5, 6, 4};
	int	arr15[6] = {1, 2, 3, 6, 4, 5};
	int	arr16[6] = {1, 2, 3, 6, 5, 4};

	ft_printf("\nstack_vsort\n");
	print_stacks(stack_vsorted);
	test_vsort_top3(stack_vsorted, arr01, 6, 0);
	test_vsort_top3(stack_vsorted, arr02, 6, 0);
	test_vsort_top3(stack_vsorted, arr03, 6, 0);
	test_vsort_top3(stack_vsorted, arr04, 6, 0);
	test_vsort_top3(stack_vsorted, arr05, 6, 0);
	test_vsort_top3(stack_vsorted, arr06, 6, 0);
	test_vsort_top3(stack_vsorted, arr11, 6, 0);
	test_vsort_top3(stack_vsorted, arr12, 6, 0);
	test_vsort_top3(stack_vsorted, arr13, 6, 0);
	test_vsort_top3(stack_vsorted, arr14, 6, 0);
	test_vsort_top3(stack_vsorted, arr15, 6, 0);
	test_vsort_top3(stack_vsorted, arr16, 6, 0);

	ft_printf("\nstack_msort\n");
	print_stacks(stack_msorted);
	test_msort_top3(stack_msorted, arr01, 6, 0);
	test_msort_top3(stack_msorted, arr02, 6, 0);
	test_msort_top3(stack_msorted, arr03, 6, 0);
	test_msort_top3(stack_msorted, arr04, 6, 0);
	test_msort_top3(stack_msorted, arr05, 6, 0);
	test_msort_top3(stack_msorted, arr06, 6, 0);
	test_msort_top3(stack_msorted, arr11, 6, 0);
	test_msort_top3(stack_msorted, arr12, 6, 0);
	test_msort_top3(stack_msorted, arr13, 6, 0);
	test_msort_top3(stack_msorted, arr14, 6, 0);
	test_msort_top3(stack_msorted, arr15, 6, 0);
	test_msort_top3(stack_msorted, arr16, 6, 0);

	ft_printf("\nstack_asort\n");
	print_stacks(stack_asorted);
	test_asort_top3(stack_asorted, arr01, 6, 0);
	test_asort_top3(stack_asorted, arr02, 6, 0);
	test_asort_top3(stack_asorted, arr03, 6, 0);
	test_asort_top3(stack_asorted, arr04, 6, 0);
	test_asort_top3(stack_asorted, arr05, 6, 0);
	test_asort_top3(stack_asorted, arr06, 6, 0);
	test_asort_top3(stack_asorted, arr11, 6, 0);
	test_asort_top3(stack_asorted, arr12, 6, 0);
	test_asort_top3(stack_asorted, arr13, 6, 0);
	test_asort_top3(stack_asorted, arr14, 6, 0);
	test_asort_top3(stack_asorted, arr15, 6, 0);
	test_asort_top3(stack_asorted, arr16, 6, 0);

	ft_printf("\nstack_dsort\n");
	print_stacks(stack_dsorted);
	test_dsort_top3(stack_dsorted, arr01, 6, 0);
	test_dsort_top3(stack_dsorted, arr02, 6, 0);
	test_dsort_top3(stack_dsorted, arr03, 6, 0);
	test_dsort_top3(stack_dsorted, arr04, 6, 0);
	test_dsort_top3(stack_dsorted, arr05, 6, 0);
	test_dsort_top3(stack_dsorted, arr06, 6, 0);
	test_dsort_top3(stack_dsorted, arr11, 6, 0);
	test_dsort_top3(stack_dsorted, arr12, 6, 0);
	test_dsort_top3(stack_dsorted, arr13, 6, 0);
	test_dsort_top3(stack_dsorted, arr14, 6, 0);
	test_dsort_top3(stack_dsorted, arr15, 6, 0);
	test_dsort_top3(stack_dsorted, arr16, 6, 0);

	free_stacks(&stack_msorted);
	free_stacks(&stack_vsorted);
	free_stacks(&stack_asorted);
	free_stacks(&stack_dsorted);
	return (0);
}

int top2_sort_test(void)
{
	t_psstacks *stack_vsorted;
	t_psstacks *stack_msorted;
	t_psstacks *stack_asorted;
	t_psstacks *stack_dsorted;
	int v_sorted[4] = {2, 1, 4, 5};
	int m_sorted[4] = {1, 2, 5, 4};
	int a_sorted[4] = {1, 2, 4, 5};
	int d_sorted[4] = {2, 1, 5, 4};
	stack_vsorted = init_stacks_from_array(v_sorted, 4);
	stack_msorted = init_stacks_from_array(m_sorted, 4);
	stack_asorted = init_stacks_from_array(a_sorted, 4);
	stack_dsorted = init_stacks_from_array(d_sorted, 4);
	w_pbn(&stack_vsorted, 2);
	w_pbn(&stack_msorted, 2);
	w_pbn(&stack_asorted, 2);
	w_pbn(&stack_dsorted, 2);

	int	arr01[4] = {1, 2, 4, 5};
	int	arr02[4] = {2, 1, 4, 5};
	int	arr03[4] = {1, 2, 5, 4};
	int	arr04[4] = {2, 1, 5, 4};

	ft_printf("\nstack_vsort\n");
	print_stacks(stack_vsorted);
	test_vsort_top2(stack_vsorted, arr01, 4, 0);
	test_vsort_top2(stack_vsorted, arr02, 4, 0);
	test_vsort_top2(stack_vsorted, arr03, 4, 0);
	test_vsort_top2(stack_vsorted, arr04, 4, 0);

	ft_printf("\nstack_msort\n");
	print_stacks(stack_msorted);
	test_msort_top2(stack_msorted, arr01, 4, 0);
	test_msort_top2(stack_msorted, arr02, 4, 0);
	test_msort_top2(stack_msorted, arr03, 4, 0);
	test_msort_top2(stack_msorted, arr04, 4, 0);

	ft_printf("\nstack_asort\n");
	print_stacks(stack_asorted);
	test_asort_top2(stack_asorted, arr01, 4, 0);
	test_asort_top2(stack_asorted, arr02, 4, 0);
	test_asort_top2(stack_asorted, arr03, 4, 0);
	test_asort_top2(stack_asorted, arr04, 4, 0);

	ft_printf("\nstack_dsort\n");
	print_stacks(stack_dsorted);
	test_dsort_top2(stack_dsorted, arr01, 4, 0);
	test_dsort_top2(stack_dsorted, arr02, 4, 0);
	test_dsort_top2(stack_dsorted, arr03, 4, 0);
	test_dsort_top2(stack_dsorted, arr04, 4, 0);
	
	return (0);
}