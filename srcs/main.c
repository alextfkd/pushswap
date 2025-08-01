/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 23:06:03 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_cdlst_1(void)
{
	t_cdlist	*lst;
	t_cdlist	*node1;
	t_cdlist	*node2;
	t_cdlist	*node3;
	t_cdlist	*node4;

	lst = ft_cdlstinit();
	node1 = create_cdlst_node(1);
	node2 = create_cdlst_node(2);
	node3 = create_cdlst_node(3);
	node4 = create_cdlst_node(4);
	insert_nil_next(&lst, node1);
	insert_nil_next(&lst, node2);
	insert_nil_next(&lst, node3);
	insert_nil_next(&lst, node4);
	ft_printf("#1 print backward (STACK_A)\n(nil) -> 1 2 3 4\nOUTPUT: ");
	print_cdlst(lst, STACK_A);
	ft_printf("\n\n#2 print forward (STACK_B)\n(nil) -> 4 3 2 1\nOUTPUT: ");
	print_cdlst(lst, STACK_B);
	rotate_forward(&lst);
	ft_printf("\n\n#1 print backward (STACK_A)\n(nil) -> 2 3 4 1\nOUTPUT: ");
	print_cdlst(lst, STACK_A);
	swap_forward(&lst);
	ft_printf("\n\n#1 print backward (STACK_A)\n(nil) -> 2 3 1 4\nOUTPUT: ");
	print_cdlst(lst, STACK_A);
	del_cdlstnode(lst);
	del_cdlstnode(node1);
	del_cdlstnode(node2);
	del_cdlstnode(node3);
	del_cdlstnode(node4);
	return (0);
}

int	cdlist_count_sorted(t_cdlist *head)
{
	t_cdlist 	*ptr;
	int			count;

	ptr = head;
	count = 1;
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
	t_cdlist	*head;
	int			r_count;
	int			sorted_count;

	if (push_toward == PUSH_B2A)
		head = cdlst_find_head((*stacks)->stack_b);
	else if (push_toward == PUSH_A2B)
		head = cdlst_find_head((*stacks)->stack_a);
	else
		return (1);
	sorted_count = cdlist_count_sorted(head);
	ft_printf("sorted_count: [%d]\n", sorted_count);
	print_stacks(*stacks);
	//w_sb(stacks);
	print_stacks(*stacks);
	//w_rb(stacks);
	print_stacks(*stacks);
	r_count = rotate_merge(stacks, sorted_count, order, push_toward);
	print_stacks(*stacks);
	ft_printf("AAA\n");
	rev_rotate_merge(stacks, r_count, order, push_toward);
	print_stacks(*stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	t_psstacks	*stacks;
	int	status;

	if (argc == 1)
		return (0);
	status = 0;
	status += validate_args(argc, argv);
	if (status > 0)
	{
		ft_perror(status);
		exit(status);
	}
	ft_printf("\n");
	stacks = init_stacks(argc, argv);
	print_stacks(stacks);
	//w_pb(&stacks);
	w_pb(&stacks);
	w_pb(&stacks);
	w_pb(&stacks);
	sort_top3_stacks(&stacks, 1, 1);
	do_ops(&stacks);
	print_stacks(stacks);
	merge_sorted_substacks(&stacks, ORDER_DESC, PUSH_A2B);
	print_stacks(stacks);
	return (1);
	w_pb(&stacks);
	w_pb(&stacks);
	w_pb(&stacks);
	print_stacks(stacks);
	sort_top3_stacks(&stacks, -1, -1);
	do_ops(&stacks);
	print_stacks(stacks);
	merge_sorted_substacks(&stacks, ORDER_ASC, PUSH_A2B);
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
	ft_printf("total ops: %d", stacks->op_count);
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
