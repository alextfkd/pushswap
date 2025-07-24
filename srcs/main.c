/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/07/24 22:29:01 by tkatsuma         ###   ########.fr       */
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

int	stack_a_top3_status(t_psstacks ** stacks)
{
	t_cdlist	*top;
	int			topv;
	int			topnv;
	int			topnnv;

	top = cdlst_find_head((*stacks)->stack_a);
	topv = top->content->value;
	topnv = top->next->content->value;
	topnnv = top->next->next->content->value;
	ft_printf("topv = %s\n" ,ft_itoa(topv));
	ft_printf("topnv = %s\n" ,ft_itoa(topnv));
	ft_printf("topnnv = %s\n" ,ft_itoa(topnnv));
	if (topv < topnv && topnv < topnnv)
		return (321);
	else if (topv < topnnv && topnnv < topnv)
		return (231);
	else if (topnv < topv && topv < topnnv)
		return (312);
	else if (topnv < topnnv && topnnv < topv)
		return (132);
	else if (topnnv < topv && topv < topnv)
		return (213);
	else if (topnnv < topnv && topnv < topv)
		return (123);
	return(0);
}

int	sort_stack_a_top3(t_psstacks ** stacks)
{
	int top3_status;

	top3_status = stack_a_top3_status(stacks);
	ft_printf("status = %s\n" ,ft_itoa(top3_status));
	if (top3_status == 123)
	{
		ft_printf("123\n");
		w_sa(stacks);
		w_ra(stacks);
		w_sa(stacks);
		w_rra(stacks);
		w_sa(stacks);
	}
	else if (top3_status == 132)
	{
		ft_printf("132\n");
		w_sa(stacks);
		w_ra(stacks);
		w_sa(stacks);
		w_rra(stacks);
	}
	else if (top3_status == 321)
	{
	}
	else if (top3_status == 231)
	{
		w_ra(stacks);
		w_sa(stacks);
		w_rra(stacks);
	}
	else if (top3_status == 213)
	{
		w_ra(stacks);
		w_sa(stacks);
		w_rra(stacks);
		w_sa(stacks);
	}
	else if (top3_status == 213)
	{
		w_sa(stacks);
	}
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
	sort_stack_a_top3(&stacks);
	print_stacks(stacks);
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
