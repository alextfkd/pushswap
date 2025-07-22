/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/07/22 15:54:34 by marvin           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	status;

	status = 0;
	status += validate_args(argc, argv);
	if (status > 0)
	{
		ft_perror(status);
		exit(status);
	}
	test_cdlst_1();
	return (0);
}
