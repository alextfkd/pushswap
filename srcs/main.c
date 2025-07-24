/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/07/24 18:58:49 by tkatsuma         ###   ########.fr       */
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

int	*create_argv_int_array(int argc, char **argv)
{
	int	*arr;
	int	i;

	i = 1;
	if (argc <= 0)
		return(NULL);
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (arr == NULL)
		return (NULL);
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (arr);
}

int	load_args_to_stack_a(int argc, char**argv, t_psstacks **stacks)
{
	int			i;
	int			status;
	int			*arr;
	t_cdlist	*node;

	i = 0;
	status = 0;
	arr = create_argv_int_array(argc, argv);
	while (i < argc - 1)
	{
		ft_printf("arr[%d] = %d\n", i, arr[i]);
		node = create_cdlst_node(arr[i]);
		status = insert_nil_next(&((*stacks)->stack_a), node);
		if (status > 0)
		{
			free (arr);
			return (1);
		}
		i++;
	}
	free (arr);
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
	stacks = create_stacks();
	load_args_to_stack_a(argc, argv, &stacks);
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
	/*
	*/
	return (0);
}
