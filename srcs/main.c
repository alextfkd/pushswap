/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/14 22:19:50 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_m_or_v(t_psstacks *stacks)
{
	t_cdlist	*a;
	t_cdlist	*b;
	int			M;
	int			V;

	M = ORDER_DESC;
	V = ORDER_ASC;
	a = cdlst_find_head(stacks->stack_a);
	b = cdlst_find_head(stacks->stack_b);
	if (a->content == NULL || a->next->content == NULL)
	{
		if (b->content->value > b->next->content->value)
			return (M);
		return (V);
	}
	if (b->content == NULL || b->next->content == NULL)
	{
		if (a->content->value > a->next->content->value)
			return (M);
		return (V);
	}
	if (b->content->value > b->next->content->value)
	{
		if (a->content->value > a->next->content->value)
			return (M);
	}
	if (b->content->value < b->next->content->value)
	{
		if (a->content->value < a->next->content->value)
			return (V);
	}
	return (0);
}

int	merge_test3(int *arr)
{
	//int	arr01[12] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int	arr02[24] = {24, 23, 22, 21, 20, 19, 18, 17, 16 ,15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	t_psstacks	*test_stack01;
	//test_stack01 = init_stacks_from_array(arr01, 12);
	test_stack01 = init_stacks_from_array(arr02, 24);
	ft_printf("INITIAL\n");
	print_stacks(test_stack01);
	ft_printf("\n");
	int i = 0;
	int arrlen = 24 / 8;
	while (i < arrlen)
	{
		ft_printf("%d", arr[i++]);
	}
	ft_printf("\n");
	i = 0;
	while (i <= arrlen)
	{
		ft_printf("NEW LOOP\n\n");
		w_pbn(&test_stack01, 3);
		print_stacks(test_stack01);
		//if (arr[i] == 1 && arr[i + 1] == 0)
		if (arr[arrlen - i] == 3)
			vsort_top3_stacks(&test_stack01);
		//else if (arr[i] == 0 && arr[i + 1] == 1)
		else if (arr[arrlen - i] == 3)
			msort_top3_stacks(&test_stack01);
		else
			asort_top3_stacks(&test_stack01);
		do_ops(&test_stack01);
		w_pbn(&test_stack01, 3);
		print_stacks(test_stack01);
		ft_printf("672 line\n\n");
		i++;
	}
	while (cdlst_len(test_stack01->stack_b) > 0)
		w_pa(&test_stack01);

	int j = 0;
	while (j < 8)
	{
		ft_printf("\n\n");
		print_stacks(test_stack01);
		i = 0;
		while (i < 24)
		{
			t_cdlist *top;
			top = cdlst_find_head(test_stack01->stack_a);
			if ((top->content->value & (1 << j)) != 0)
				w_ra(&test_stack01);
			else
				w_pb(&test_stack01);
			i++;
			print_stacks(test_stack01);
		}
		print_stacks(test_stack01);
		while (cdlst_len(test_stack01->stack_b) > 0)
			w_pa(&test_stack01);
		print_stacks(test_stack01);
		j++;
	}
	ft_printf("[%d]\n", cdlst_find_head(test_stack01->stack_a)->content->value);
	ft_printf("FINISHED [%d]\n", test_stack01->op_count);
	return (0);
}

int	presort_stacks(t_psstacks **stacks)
{
	int i;
	int arrlen;

	i = 0;
	arrlen = cdlst_len((*stacks)->stack_a) + cdlst_len((*stacks)->stack_b);
	while (i <= arrlen / 6)
	{
		w_pbn(stacks, 3);
		asort_top3_stacks(stacks);
		do_ops(stacks);
		w_pbn(stacks, 3);
		i++;
	}
	return (0);
}

int	push_all_to_stack_a(t_psstacks **stacks)
{
	while (cdlst_len((*stacks)->stack_b) > 0)
		w_pa(stacks);
	return (0);
}

int	radix_sort_stacks(t_psstacks **stacks, int n)
{
	t_cdlist *top;
	int i;
	int j;

	i = 0;
	j = 31;
	while (j < 32 + 32)
	{
		//ft_printf("\n\n");
		//print_stacks(*stacks);
		i = 0;
		while (i < n)
		{
			//ft_printf("RSORT -> [%d]\n", (j % 32));
			top = cdlst_find_head((*stacks)->stack_a);
			if (((top->content->value & (1 << (j % 32))) != 0) && (j % 32 != 31))
				w_ra(stacks);
				//w_rra(stacks);
			else if (((top->content->value & (1 << (j % 32))) == 0) && (j % 32 != 31))
				w_pb(stacks);
			else if (((top->content->value & (1 << (j % 32))) != 0) && (j % 32 == 31))
				w_pb(stacks);
			else
				w_ra(stacks);
			i++;
			//print_stacks(*stacks);
		}
		//print_stacks(*stacks);
		push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1 )
			break;
		//print_stacks(*stacks);
		j++;
	}
	return (0);
}

int	radix_sort_stacks2(t_psstacks **stacks, int n)
{
	t_cdlist *top;
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 32)
	{
		//ft_printf("\n\n");
		//print_stacks(*stacks);
		i = 0;
		while (i < n)
		{
			//ft_printf("RSORT -> [%d]\n", (j % 32));
			top = cdlst_find_head((*stacks)->stack_a);
			if ((top->content->value & (1 << j)) != 0)
				w_ra(stacks);
			else
				w_pb(stacks);
			i++;
			//print_stacks(*stacks);
		}
		//print_stacks(*stacks);
		push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1 )
			break;
		//print_stacks(*stacks);
		j++;
	}
	return (0);
}


int	set_rank_for_sorted(t_psstacks **stacks)
{
	int				i;
	t_cdlist	*tmp;

	i = 0;
	//ft_printf("RANK FOR SORTED-> %p\n", (*stacks)->stack_ops->next->content);
	tmp = cdlst_find_head((*stacks)->stack_a);
	while (tmp->content != NULL)
	{
		tmp->content->value = i++;
		//tmp->content->rank = i++;
		tmp = tmp->next;
	}
	//ft_printf("tail[%d]", tmp->prev->content->rank);
	return (0);
}

int	reverse_sorted(t_psstacks **stacks)
{
	t_cdlist	*tmp;

	//ft_printf("REVERSE SORT -> %p\n", (*stacks)->stack_ops->next->content);
	tmp = (*stacks)->stack_ops->next;
	if (tmp == NULL)
	{
		(*stacks)->stack_ops->next = (*stacks)->stack_ops;
		ft_printf("ERROR9");
		exit(1);
	}
	//ft_printf("tmp -> %d", (*stacks)->stack_ops->next->content->value);
	while (tmp->content != NULL)
	{
		//ft_printf("[%d]",tmp->content->value);
		if (tmp->content->value == PA)
			w_pb(stacks);
		else if (tmp->content->value == PB)
			w_pa(stacks);
		else if (tmp->content->value == SA)
			w_sa(stacks);
		else if (tmp->content->value == SB)
			w_sb(stacks);
		else if (tmp->content->value == SS)
			w_ss(stacks);
		else if (tmp->content->value == RA)
			w_rra(stacks);
		else if (tmp->content->value == RB)
			w_rrb(stacks);
		else if (tmp->content->value == RR)
			w_rrr(stacks);
		else if (tmp->content->value == RRA)
			w_ra(stacks);
		else if (tmp->content->value == RRB)
			w_rb(stacks);
		else if (tmp->content->value == RRR)
			w_rr(stacks);
		else
			break;
		tmp = tmp->next;
	}
	return (0);
}

int	print_sort_ops(t_psstacks **stacks)
{
	t_cdlist	*tmp;

	tmp = cdlst_find_tail((*stacks)->stack_ops);
	/*
	tmp = (*stacks)->stack_ops->next;
	if (tmp == NULL)
	{
		(*stacks)->stack_ops->next = (*stacks)->stack_ops;
		ft_printf("ERROR9");
		exit(1);
	}
	*/
	//ft_printf("tmp -> %d", (*stacks)->stack_ops->next->content->value);
	while (tmp->content != NULL)
	{
		if (tmp->content->value == PA)
			ft_printf("pa\n");
		else if (tmp->content->value == PB)
			ft_printf("pb\n");
		else if (tmp->content->value == SA)
			ft_printf("sa\n");
		else if (tmp->content->value == SB)
			ft_printf("sb\n");
		else if (tmp->content->value == SS)
			ft_printf("ss\n");
		else if (tmp->content->value == RA)
			ft_printf("ra\n");
		else if (tmp->content->value == RB)
			ft_printf("rb\n");
		else if (tmp->content->value == RR)
			ft_printf("rr\n");
		else if (tmp->content->value == RRA)
			ft_printf("rra\n");
		else if (tmp->content->value == RRB)
			ft_printf("rrb\n");
		else if (tmp->content->value == RRR)
			ft_printf("rrr\n");
		else
			break;
		tmp = tmp->prev;
	}
	return (0);
}

int	merge_test4(void)
{
	t_psstacks	*test_stack01;
	int	arr02[24] = {24, 23, 22, 14, 13, 12, 11, 21, 20, 19, 18, 17, 16, 15, -10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	test_stack01 = init_stacks_from_array(arr02, 24);
	//print_stacks(test_stack01);
	int n = cdlst_len(test_stack01->stack_a);
	presort_stacks(&test_stack01);
	push_all_to_stack_a(&test_stack01);
	radix_sort_stacks(&test_stack01, n);
	set_rank_for_sorted(&test_stack01);
	reverse_sorted(&test_stack01);
	free(test_stack01->stack_ops);
	test_stack01->stack_ops = ft_cdlstinit();
	test_stack01->op_count = 0;
	free(test_stack01->a_ops);
	free(test_stack01->b_ops);
	presort_stacks(&test_stack01);
	push_all_to_stack_a(&test_stack01);
	radix_sort_stacks(&test_stack01, n);
	//ft_printf("FINISHED [%d]\n", test_stack01->op_count);
	//print_sort_ops(&test_stack01);
	return (0);
}


int	main(int argc, char **argv)
{
	t_psstacks	*stacks;
	int	status;

	//(void)argc;
	//(void)argv;
	//merge_test4();
	//main_2();
	//top2_sort_test();
	//top3_sort_test();
	//merge_test();
	//merge_test4();
	//merge_test2();
	//return (0);
	if (argc == 1)
		return (0);
	status = 0;
	if (argc == 2)
	{
		//ft_printf("AAA");
		char	**splitted;
		splitted = ft_split((const char *)argv[1], ' ');
		int argc2 = 1;
		while (splitted[argc2 - 1] != NULL)
		{
			argc2++;
		}
		//ft_printf("argc->[%d]", argc);
		//ft_printf("argv[0]->[%d]", argc);
		int	i;
		i = 0;
		char	**newargv;
		newargv = (char **)ft_calloc(sizeof(char *), argc2 + 1);
		newargv[0] = ft_strdup(argv[0]);
		i++;
		while (i < argc2)
		{
			newargv[i] = ft_strdup(splitted[i - 1]);
			i++;
		}
		argv = newargv;
		//ft_printf("atata 1 -> %d", argc);
		//ft_printf("atata 2 -> %d", argc2);
		//ft_printf("atata 3 -> %d", i );
		argc = argc2;
	}
	status += validate_args(argc, argv);
	if (status > 0)
	{
		ft_printf("!!!!!!!!!!!!");
		ft_perror(status);
		exit(status);
	}
	stacks = init_stacks(argc, argv);
	int n = cdlst_len(stacks->stack_a);
	presort_stacks(&stacks);
	push_all_to_stack_a(&stacks);
	radix_sort_stacks(&stacks, n);

	set_rank_for_sorted(&stacks);
	reverse_sorted(&stacks);
	free(stacks->stack_ops);
	stacks->stack_ops = ft_cdlstinit();
	stacks->op_count = 0;
	free(stacks->a_ops);
	free(stacks->b_ops);

	//presort_stacks(&stacks);
	push_all_to_stack_a(&stacks);
	radix_sort_stacks2(&stacks, n);
	print_sort_ops(&stacks);
	return (0);
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
}


