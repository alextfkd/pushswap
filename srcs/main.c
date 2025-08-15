/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/15 19:16:20 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix_sort_stacks_32th_bit(t_psstacks **stacks, int n)
{
	t_cdlist	*top;
	int			i;

	if (if_stack_a_sorted(*stacks) == 1)
		return (0);
	i = 0;
	while (i < n)
	{
		top = cdlst_find_head((*stacks)->stack_a);
		if (((top->content->value & (1U << 31)) != 0))
			w_pb(stacks);
		else
			w_ra(stacks);
		i++;
		print_stacks(*stacks);
	}
	push_all_to_stack_a(stacks);
	print_stacks(*stacks);
	return (0);
}

int	radix_sort_stacks(t_psstacks **stacks, int n)
{
	t_cdlist	*top;
	int			i;
	int			j;

	j = 0;
	while ((j < 31) && (if_stack_a_sorted(*stacks) != 1))
	{
		i = 0;
		while (i < n)
		{
			top = cdlst_find_head((*stacks)->stack_a);
			if (((top->content->value & (1U << j))) != 0)
				w_ra(stacks);
			else
				w_pb(stacks);
			print_stacks(*stacks);
			i++;
		}
		push_all_to_stack_a(stacks);
		print_stacks(*stacks);
		j++;
	}
	return (0);
}

int radix_sort_stacks_X(t_psstacks **stacks, int n)
{
	t_cdlist	*top;
	int			i;
	int			j;

	j = 31;
	while (j < 64)
	{
		i = 0;
		while (i < n)
		{
			top = cdlst_find_head((*stacks)->stack_a);
			if (((top->content->value & (1U << (j % 32))) != 0) && (j % 32 != 31))
				w_ra(stacks);
			else if (((top->content->value & (1U << (j % 32))) == 0) && (j % 32 != 31))
				w_pb(stacks);
			else if (((top->content->value & (1U << (j % 32))) != 0) && (j % 32 == 31))
				w_pb(stacks);
			else
				w_ra(stacks);
			i++;
		}
		push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1)
			break ;
		j++;
	}
	return (0);
}

int	radix_sort_stacks2(t_psstacks **stacks, int n)
{
	t_cdlist	*top;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < n)
		{
			top = cdlst_find_head((*stacks)->stack_a);
			if ((top->content->value & (1 << j)) != 0)
				w_ra(stacks);
			else
				w_pb(stacks);
			i++;
		}
		push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1)
			break ;
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_psstacks	*stacks;
	int			status;

	if (argc == 1)
		return (0);
	status = 0;
	if (argc == 2)
		split_argv1(&argc, &argv);
	status += validate_args(argc, argv);
	if (status > 0)
	{
		ft_perror(status);
		exit(status);
	}

	stacks = init_stacks(argc, argv);
	int n = cdlst_len(stacks->stack_a);
	presort_stacks(&stacks);
	push_all_to_stack_a(&stacks);
	//radix_sort_stacks_32th_bit(&stacks, n);
	radix_sort_stacks_X(&stacks, n);
	//ft_printf("!\n\n");
	//print_stacks(stacks);
	//ft_printf("\n\n");

	set_rank_for_sorted(&stacks);
	reverse_sorted(&stacks);
	delete_cdlst(&(stacks->stack_ops));
	stacks->stack_ops = ft_cdlstinit();
	stacks->op_count = 0;
	free(stacks->a_ops);
	free(stacks->b_ops);
	push_all_to_stack_a(&stacks);
	radix_sort_stacks2(&stacks, n);
	print_sort_ops(&stacks);
	free_stacks(&stacks);
	return (0);
}


