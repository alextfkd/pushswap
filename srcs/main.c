/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/01 15:41:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	cdlist_count_sorted(t_cdlist *lst)
{
	t_cdlist 	*nil;
	t_cdlist 	*ptr;
	int			count;

	nil = cdlst_find_nil(lst);
	ptr = nil->next;
	if (ptr == nil)
		return (0);
	count = 1;
	if (ptr->next->content == NULL)
		return (count);
	if (ptr->content->value < ptr->next->content->value)
	{
		while (ptr->content->value < ptr->next->content->value)
		{
			count++;
			ptr = ptr->next;
			if (ptr->next->content == NULL)
				break;
		}
		return (count);
	}
	while (ptr->content->value > ptr->next->content->value)
	{
		count++;
		ptr = ptr->next;
		if (ptr->next->content == NULL)
			break;
	}
	return (count);
}

int	merge_sorted_substacks(t_psstacks **stacks, int order, int push_toward)
{
	int			r_count;
	int			n_sort;

	(*stacks)->a_sort_len = cdlist_count_sorted((*stacks)->stack_a);
	(*stacks)->b_sort_len = cdlist_count_sorted((*stacks)->stack_b);
	//ft_printf("Stack A sorted: [%d] from head.\n", (*stacks)->a_sort_len);
	//ft_printf("Stack B sorted: [%d] from head.\n", (*stacks)->b_sort_len);
	n_sort = (*stacks)->a_sort_len + (*stacks)->b_sort_len;
	//print_stacks(*stacks);
	//w_sb(stacks);
	//print_stacks(*stacks);
	//w_rb(stacks);
	//print_stacks(*stacks);
	r_count = rotate_merge(stacks, order, push_toward);
	r_count = r_count % n_sort;

	//print_stacks(*stacks);
	//ft_printf("A sorted count -> [%d]\n", (*stacks)->a_sort_len);
	//ft_printf("B sorted count -> [%d]\n", (*stacks)->b_sort_len);
	//ft_printf("Rotate count -> [%d]\n", r_count);
	while (r_count > 0)
	{
		if (push_toward == PUSH_A2B)
			w_rrb(stacks);
		else
			w_rra(stacks);
		r_count--;
	}
	//rev_rotate_merge(stacks, r_count, order, push_toward);
	//print_stacks(*stacks);
	(*stacks)->a_sort_len = 0;
	(*stacks)->b_sort_len = 0;
	return (0);
}

t_psstacks	*create_stacks_from_cdlist(t_cdlist *stack_a, t_cdlist *stack_b)
{
	t_psstacks	*stacks;

	if (stack_a == NULL || stack_b == NULL)
		return (NULL);
	stacks = (t_psstacks *)malloc(sizeof(t_psstacks));
	if (stacks == NULL)
		return (NULL);
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	stacks->a_ops = NULL;
	stacks->b_ops = NULL;
	stacks->op_count = 0;
	stacks->a_sort_len = 0;
	stacks->b_sort_len = 0;
	return (stacks);
}


t_psstacks	*init_stacks_from_array(int *arr, int len)
{
	t_psstacks	*stacks;
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (arr == NULL || len <= 0)
		return (NULL);
	stack_a = create_stack_from_arr(arr, len);
	if (stack_a == NULL)
		return (NULL);
	stack_b = ft_cdlstinit();
	if (stack_b == NULL)
	{
		free_cdlst_node(stack_a);
		return (NULL);
	}
	stacks = create_stacks_from_cdlist(stack_a, stack_b);
	if (stacks == NULL)
	{
		free_cdlst_node(stack_a);
		free_cdlst_node(stack_b);
		return (NULL);
	}
	return (stacks);
}

void	free_stacks(t_psstacks **stacks)
{
	free_cdlst_node((*stacks)->stack_a);
	free_cdlst_node((*stacks)->stack_b);
	free(*stacks);
}

int	vsort_top3_stacks(t_psstacks **stack)
{
	return (sort_top3_stacks(stack, ORDER_ASC, ORDER_ASC));
}

int	msort_top3_stacks(t_psstacks **stack)
{
	return (sort_top3_stacks(stack, ORDER_DESC, ORDER_DESC));
}

static int	test_vsort_top3(t_psstacks *sorted, int *arr, int len)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pb(&stack);
	w_pb(&stack);
	w_pb(&stack);
	print_stacks(stack);
	ft_printf("Current status -> [%d]\n", stack_top3_status(stack->stack_a));
	vsort_top3_stacks(&stack);
	do_ops(&stack);
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

static int	test_msort_top3(t_psstacks *sorted, int *arr, int len)
{
	t_psstacks *stack;

	stack = init_stacks_from_array(arr, len);
	w_pb(&stack);
	w_pb(&stack);
	w_pb(&stack);
	print_stacks(stack);
	ft_printf("Current status -> [%d]\n", stack_top3_status(stack->stack_a));
	msort_top3_stacks(&stack);
	do_ops(&stack);
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

int	top3_sort_test(void)
{
	t_psstacks *stack_vsorted;
	t_psstacks *stack_msorted;
	int v_sorted[6] = {3, 2, 1, 4, 5, 6};
	int m_sorted[6] = {1, 2, 3, 6, 5, 4};
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
	stack_vsorted = init_stacks_from_array(v_sorted, 6);
	stack_msorted = init_stacks_from_array(m_sorted, 6);
	w_pb(&stack_vsorted);
	w_pb(&stack_vsorted);
	w_pb(&stack_vsorted);
	print_stacks(stack_vsorted);
	test_vsort_top3(stack_vsorted, arr01, 6);
	test_vsort_top3(stack_vsorted, arr02, 6);
	test_vsort_top3(stack_vsorted, arr03, 6);
	test_vsort_top3(stack_vsorted, arr04, 6);
	test_vsort_top3(stack_vsorted, arr05, 6);
	test_vsort_top3(stack_vsorted, arr06, 6);
	test_vsort_top3(stack_vsorted, arr11, 6);
	test_vsort_top3(stack_vsorted, arr12, 6);
	test_vsort_top3(stack_vsorted, arr13, 6);
	test_vsort_top3(stack_vsorted, arr14, 6);
	test_vsort_top3(stack_vsorted, arr15, 6);
	test_vsort_top3(stack_vsorted, arr16, 6);

	w_pb(&stack_msorted);
	w_pb(&stack_msorted);
	w_pb(&stack_msorted);
	print_stacks(stack_msorted);
	test_msort_top3(stack_msorted, arr01, 6);
	test_msort_top3(stack_msorted, arr02, 6);
	test_msort_top3(stack_msorted, arr03, 6);
	test_msort_top3(stack_msorted, arr04, 6);
	test_msort_top3(stack_msorted, arr05, 6);
	test_msort_top3(stack_msorted, arr06, 6);
	test_msort_top3(stack_msorted, arr11, 6);
	test_msort_top3(stack_msorted, arr12, 6);
	test_msort_top3(stack_msorted, arr13, 6);
	test_msort_top3(stack_msorted, arr14, 6);
	test_msort_top3(stack_msorted, arr15, 6);
	test_msort_top3(stack_msorted, arr16, 6);
	free_stacks(&stack_msorted);
	free_stacks(&stack_vsorted);
	return (0);
}

int	test1(t_psstacks *ctrl, int *arr, int order, int push)
{
	t_psstacks *stack_sorted;

	stack_sorted = init_stacks_from_array(arr, 6);
	ft_printf("new arr: ");
	print_stacks(stack_sorted);
	w_pb(&stack_sorted);
	w_pb(&stack_sorted);
	w_pb(&stack_sorted);
	if (order == ORDER_ASC)
		vsort_top3_stacks(&stack_sorted);
	else
		msort_top3_stacks(&stack_sorted);
	do_ops(&stack_sorted);
	merge_sorted_substacks(&stack_sorted, order, push);
	//merge_sorted_substacks(&stack_vsorted, ORDER_ASC, PUSH_A2B);
	ft_printf("control arr: ");
	print_stacks(ctrl);
	ft_printf("sorted arr:  ");
	print_stacks(stack_sorted);
	if (cmp_stacks(ctrl, stack_sorted) == 1)
	{
		ft_printf("[PASS]\n");
		ft_printf("\n\n");
		return (0);
	}
	ft_printf("[FAIL]\n");
	ft_printf("\n\n");
	exit(0);
	return (1);
}

int	merge_test(void)
{
	t_psstacks *stack_ascend_sort_in_a;
	t_psstacks *stack_ascend_sort_in_b;
	t_psstacks *stack_descend_sort_in_a;
	t_psstacks *stack_descend_sort_in_b;
	int sorted_asc[6] = {6, 5, 4, 3, 2, 1};
	int sorted_desc[6] = {1, 2, 3, 4, 5, 6};
	stack_ascend_sort_in_a = init_stacks_from_array(sorted_desc, 6);
	stack_ascend_sort_in_b = init_stacks_from_array(sorted_asc, 6);
	w_pb(&stack_ascend_sort_in_b);
	w_pb(&stack_ascend_sort_in_b);
	w_pb(&stack_ascend_sort_in_b);
	w_pb(&stack_ascend_sort_in_b);
	w_pb(&stack_ascend_sort_in_b);
	w_pb(&stack_ascend_sort_in_b);
	stack_descend_sort_in_a = init_stacks_from_array(sorted_asc, 6);
	stack_descend_sort_in_b = init_stacks_from_array(sorted_desc, 6);
	w_pb(&stack_descend_sort_in_b);
	w_pb(&stack_descend_sort_in_b);
	w_pb(&stack_descend_sort_in_b);
	w_pb(&stack_descend_sort_in_b);
	w_pb(&stack_descend_sort_in_b);
	w_pb(&stack_descend_sort_in_b);
	ft_printf("Sorted array for control\n\n");
	ft_printf("ascend sort in A\n");
	print_stacks(stack_ascend_sort_in_a);
	ft_printf("ascend sort in B\n");
	print_stacks(stack_ascend_sort_in_b);
	ft_printf("descend sort in A\n");
	print_stacks(stack_descend_sort_in_a);
	ft_printf("descend sort in B\n");
	print_stacks(stack_descend_sort_in_b);
	ft_printf("\n\n");
	int	arr01[6] = {1, 2, 3, 4, 5, 6};
	int	arr02[6] = {1, 2, 4, 3, 5, 6};
	int	arr03[6] = {1, 2, 5, 4, 3, 6};
	int	arr04[6] = {1, 2, 6, 4, 3, 5};
	int	arr05[6] = {1, 3, 4, 2, 6, 5};
	int	arr06[6] = {1, 3, 5, 2, 6, 4};
	int	arr07[6] = {1, 3, 6, 2, 5, 4};
	int	arr08[6] = {1, 4, 5, 2, 3, 6};
	int	arr09[6] = {1, 4, 6, 2, 3, 5};
	int	arr10[6] = {1, 5, 6, 2, 3, 4};
	int	arr11[6] = {2, 3, 4, 1, 5, 6};
	int	arr12[6] = {2, 3, 5, 1, 4, 6};
	int	arr13[6] = {2, 3, 6, 1, 5, 4};
	int	arr14[6] = {2, 4, 5, 1, 3, 6};
	int	arr15[6] = {2, 4, 6, 1, 3, 5};
	int	arr16[6] = {2, 5, 6, 1, 3, 4};
	int	arr17[6] = {3, 4, 5, 1, 2, 6};
	int	arr18[6] = {3, 4, 6, 1, 2, 5};
	int	arr19[6] = {3, 5, 6, 1, 2, 4};
	int	arr20[6] = {4, 5, 6, 1, 2, 3};
	int	status;
	status = 0;
	status += test1(stack_ascend_sort_in_b, arr01, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr02, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr03, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr04, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr05, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr06, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr07, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr08, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr09, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr10, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr11, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr12, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr13, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr14, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr15, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr16, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr17, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr18, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr19, ORDER_ASC, PUSH_A2B);
	status += test1(stack_ascend_sort_in_b, arr20, ORDER_ASC, PUSH_A2B);

	status += test1(stack_ascend_sort_in_a, arr01, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr02, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr03, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr04, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr05, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr06, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr07, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr08, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr09, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr10, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr11, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr12, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr13, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr14, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr15, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr16, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr17, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr18, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr19, ORDER_ASC, PUSH_B2A);
	status += test1(stack_ascend_sort_in_a, arr20, ORDER_ASC, PUSH_B2A);

	status += test1(stack_descend_sort_in_b, arr01, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr02, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr03, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr04, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr05, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr06, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr07, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr09, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr10, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr11, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr12, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr13, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr14, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr15, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr16, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr17, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr18, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr19, ORDER_DESC, PUSH_A2B);
	status += test1(stack_descend_sort_in_b, arr20, ORDER_DESC, PUSH_A2B);

	status += test1(stack_descend_sort_in_a, arr01, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr02, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr03, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr04, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr05, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr06, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr07, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr08, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr09, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr10, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr11, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr12, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr13, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr14, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr15, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr16, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr17, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr18, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr19, ORDER_DESC, PUSH_B2A);
	status += test1(stack_descend_sort_in_a, arr20, ORDER_DESC, PUSH_B2A);

	if (status == 0)
		ft_printf("SUCCESS!!!\n");
	else
		ft_printf("FAILURE!!!\n");
	return (0);
}

int	merge_test2(void)
{
	/*
	t_psstacks *stack_ascend_sort_in_a;
	t_psstacks *stack_ascend_sort_in_b;
	//t_psstacks *stack_descend_sort_in_a;
	//t_psstacks *stack_descend_sort_in_b;
	int sorted_asc[6] = {6, 5, 4, 3, 2, 1};
	int sorted_desc[6] = {1, 2, 3, 4, 5, 6};
	stack_ascend_sort_in_a = init_stacks_from_array(sorted_desc, 6);
	stack_ascend_sort_in_b = init_stacks_from_array(sorted_asc, 6);
	*/
	t_psstacks	*test_stack01;

	int	arr01[12] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	test_stack01 = init_stacks_from_array(arr01, 12);
	ft_printf("INITIAL\n");
	print_stacks(test_stack01);
	ft_printf("\n");
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	vsort_top3_stacks(&test_stack01);
	do_ops(&test_stack01);
	ft_printf("VSORTED\n");
	ft_printf("\n");
	print_stacks(test_stack01);
	ft_printf("\n");
	ft_printf("A stack sorted count: [%d]\n", cdlist_count_sorted((test_stack01)->stack_a));
	ft_printf("B stack sorted count: [%d]\n", cdlist_count_sorted((test_stack01)->stack_b));

	w_pbn(&test_stack01, cdlist_count_sorted((test_stack01)->stack_a));
	w_pbn(&test_stack01, 3);

	msort_top3_stacks(&test_stack01);
	do_ops(&test_stack01);
	ft_printf("MSORTED\n");
	ft_printf("\n");
	print_stacks(test_stack01);
	ft_printf("\n");
	ft_printf("A stack sorted count: [%d]\n", cdlist_count_sorted((test_stack01)->stack_a));
	ft_printf("B stack sorted count: [%d]\n", cdlist_count_sorted((test_stack01)->stack_b));

	merge_sorted_substacks(&test_stack01, ORDER_DESC, PUSH_B2A);
	print_stacks(test_stack01);


	int i = cdlist_count_sorted((test_stack01)->stack_b);
	//int i = 3;
	while (i > 0)
	{
		w_pa(&test_stack01);
		i--;
		ft_printf("current i = [%d]\n", i);
	}
	ft_printf("n485\n");
	//w_pan(&test_stack01, cdlist_count_sorted((test_stack01)->stack_a));


	print_stacks(test_stack01);
	ft_printf("n491\n");
	merge_sorted_substacks(&test_stack01, ORDER_ASC, PUSH_B2A);
	print_stacks(test_stack01);

	i = cdlist_count_sorted((test_stack01)->stack_a);
	//int i = 3;
	while (i > 0)
	{
		w_pb(&test_stack01);
		i--;
		ft_printf("current i = [%d]\n", i);
	}
	/*
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	*/
	merge_sorted_substacks(&test_stack01, ORDER_ASC, PUSH_B2A);
	print_stacks(test_stack01);
	ft_printf("FINISHED in [%d] moves", test_stack01->op_count);
	/*
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	w_pb(&test_stack01);
	vsort_top3_stacks(&test_stack01);
	merge_sorted_substacks(&test_stack01, ORDER_ASC, PUSH_B2A);
	*/
	return (0);
}

int	ft_power(int base, int order)
{
	if (order <= 0)
		return (1);
	return (base * ft_power(base, order - 1));
}

int	calculate_order(int len)
{
	int	order;
	int	temp;

	order = 0;
	temp = 3;
	while (temp < len * 2)
	{
		order++;
		temp = temp * 2;
	}
	ft_printf("len = [%d], ", len);
	ft_printf("order = [%d]\n", order);
	ft_printf("power = [%d]\n", 6 * ft_power(2, order));
	return (order);
}

int	*create_order_arr(int *prev_arr, int order)
{
	int	*arr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	arr = (int *)malloc(sizeof(int) * ft_power(2, order));
	arr[i] = 1;
	if (prev_arr == NULL)
		return (arr);
	while (j < ft_power(2, order - 1))
	{
		if (prev_arr[j++] == 1)
		{
			arr[i++] = 1;
			arr[i++] = 0;
		}
		else
		{
			arr[i++] = 0;
			arr[i++] = 1;
		}
	}
	return (arr);
}

int	*create_sort_orders(int len)
{
	int	order;
	order = calculate_order(len);
	ft_printf("CURRENT 2 ^ ORDER = %d\n", ft_power(2, order));
	int	*arr;
	int	*prev_arr;
	int	iter;
	iter = 0;
	arr = NULL;
	while (iter < order)
	{
		ft_printf("!\n");
		prev_arr = arr;
		arr = create_order_arr(prev_arr, iter++);
		ft_printf("!\n");
		if (arr == NULL)
			ft_printf("X\n");
		if (prev_arr != NULL)
		{
			ft_printf("?\n");
			free (prev_arr);
		}
	}
	prev_arr = arr;
	arr = (int *)malloc(sizeof(int) * len);
	int	i;
	i = 0;
	int j;
	j = 0;
	while (j < len - ft_power(2, order - 1))
	{
		if (prev_arr[j++] == 1)
		{
			arr[i++] = 1;
			arr[i++] = 0;
		}
		else
		{
			arr[i++] = 0;
			arr[i++] = 1;
		}
	}
	while (j < ft_power(2, order - 1))
	{
		arr[i++] = prev_arr[j++];
	}
	i = 0;
	while (i < len)
	{
		ft_printf("%d", arr[i++]);
	}
	ft_printf("\n");
	return (arr);
}

int	merge_test3(int *arr)
{
	int	arr01[12] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	t_psstacks	*test_stack01;
	test_stack01 = init_stacks_from_array(arr01, 12);
	ft_printf("INITIAL\n");
	print_stacks(test_stack01);
	ft_printf("\n");
	int i = 0;
	int arrlen = 4;
	while (i < arrlen)
	{
		ft_printf("%d", arr[i++]);
	}
	ft_printf("\n");
	i = 0;
	while (i < arrlen)
	{
		w_pb(&test_stack01);
		w_pb(&test_stack01);
		w_pb(&test_stack01);
		print_stacks(test_stack01);
		//if (arr[i] == 1 && arr[i + 1] == 0)
		if (arr[i] == 1)
			vsort_top3_stacks(&test_stack01);
		//else if (arr[i] == 0 && arr[i + 1] == 1)
		else if (arr[i] == 0)
			msort_top3_stacks(&test_stack01);
		else
			return (1);
		do_ops(&test_stack01);
		w_pb(&test_stack01);
		w_pb(&test_stack01);
		w_pb(&test_stack01);
		print_stacks(test_stack01);
		//w_pbn(&test_stack01, cdlist_count_sorted((test_stack01)->stack_a));
		if (test_stack01->stack_a->next->content == NULL)
		{
			w_pan(&test_stack01, cdlist_count_sorted((test_stack01)->stack_b));
			print_stacks(test_stack01);
			merge_sorted_substacks(&test_stack01, ORDER_ASC, PUSH_B2A);
			print_stacks(test_stack01);
			w_pan(&test_stack01, cdlist_count_sorted((test_stack01)->stack_b));
			print_stacks(test_stack01);
			merge_sorted_substacks(&test_stack01, ORDER_ASC, PUSH_B2A);
			print_stacks(test_stack01);
			break;

		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	//t_psstacks	*stacks;
	//int	status;

	(void)argc;
	(void)argv;
	//main_2();
	//merge_test();
	merge_test2();
	int *arr = create_sort_orders(4);
	merge_test3(arr);

	//stacks = init_stacks(argc, argv);
	//return(0);
	/*
	if (argc == 1)
		return (0);
	status = 0;
	status += validate_args(argc, argv);
	if (status > 0)
	{
		ft_perror(status);
		exit(status);
	}
	*/
	/*
	ft_printf("\n");
	stacks = init_stacks(argc, argv);
	print_stacks(stacks);
	//w_pb(&stacks);
	w_pb(&stacks);
	w_pb(&stacks);
	w_pb(&stacks);
	msort_top3_stacks(&stacks);
	do_ops(&stacks);
	print_stacks(stacks);
	merge_sorted_substacks(&stacks, ORDER_DESC, PUSH_A2B);
	print_stacks(stacks);
	return (1);
	*/
	/*
	w_pb(&stacks);
	w_pb(&stacks);
	w_pb(&stacks);
	print_stacks(stacks);
	sort_top3_stacks(&stacks, -1, -1);
	do_ops(&stacks);
	print_stacks(stacks);
	merge_sorted_substacks(&stacks, ORDER_ASC, PUSH_A2B);
	*/
	//merge_sorted_substacks(&stacks, ORDER_ASC, PUSH_A2B);
	//print_stacks(stacks);
	/*
	merge_sorted_substacks(&stacks, ORDER_DESC, PUSH_B2A);
	print_stacks(stacks);
	*/
	/*
	print_stacks(stacks);
	w_pa(&stacks);
	w_pa(&stacks);
	w_pa(&stacks);
	w_pa(&stacks);
	w_pa(&stacks);
	w_pa(&stacks);
	merge_sorted_substacks(&stacks, ORDER_DESC, PUSH_B2A);
	print_stacks(stacks);
	*/
	//b2a_descend_merge(&stacks);
	//ft_printf("total ops: %d", stacks->op_count);
	/*
	w_sa(&stacks);
	if (stacks->status == 1)
		return (1);
	print_stacks(stacks);
	w_ra(&stacks);
	if (stacks->status == 1)
		return (1);
	print_stacks(stacks);
	w_sa(&stacks);
	if (stacks->status == 1)
		return (1);
	print_stacks(stacks);
	w_rra(&stacks);
	if (stacks->status == 1)
		return (1);
	print_stacks(stacks);
	w_sa(&stacks);
	print_stacks(stacks);
	if (stacks->status == 1)
		return (1);
	*/
	/*
	w_pb(&stacks);
	print_stacks(stacks);
	w_pb(&stacks);
	print_stacks(stacks);
	w_ss(&stacks);
	print_stacks(stacks);
	if_stack_a_sorted(stacks);
	w_sb(&stacks);
	print_stacks(stacks);
	if_stack_b_sorted(stacks);
	w_ss(&stacks);
	print_stacks(stacks);
	*/
	/*
	print_stacks(stacks);
	swap_forward(&(stacks->stack_a));
	print_stacks(stacks);
	push_to_b_stack(&stacks);
	print_stacks(stacks);
	push_to_b_stack(&stacks);
	print_stacks(stacks);
	swap_forward(&(stacks->stack_a));
	print_stacks(stacks);
	push_to_b_stack(&stacks);
	print_stacks(stacks);
	swap_forward(&(stacks->stack_b));
	print_stacks(stacks);
	rotate_forward(&(stacks->stack_b));
	print_stacks(stacks);
	push_to_a_stack(&stacks);
	print_stacks(stacks);
	push_to_a_stack(&stacks);
	print_stacks(stacks);
	swap_forward(&(stacks->stack_a));
	print_stacks(stacks);
	*/
	return (0);
}


