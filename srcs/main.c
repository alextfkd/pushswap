/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/15 20:00:41 by tkatsuma         ###   ########.fr       */
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
		//print_stacks(*stacks);
	}
	push_all_to_stack_a(stacks);
	//print_stacks(*stacks);
	return (0);
}

int	radix_sort_stacks(t_psstacks **stacks, int n)
{
	t_cdlist	*top;
	int			i;
	int			j;

	j = 0;
	while ((j < 32) && (if_stack_a_sorted(*stacks) != 1))
	{
		i = 0;
		while (i < n)
		{
			top = cdlst_find_head((*stacks)->stack_a);
			if (((top->content->value & (1U << (j % 32)))) != 0)
				w_ra(stacks);
			else
				w_pb(stacks);
			//print_stacks(*stacks);
			i++;
		}
		push_all_to_stack_a(stacks);
		//print_stacks(*stacks);
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
	//while (j < 63)
	while (j < 64)
	{
		i = 0;
		//ft_printf("j = [%d]\n", j % 32);
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
			if ((top->content->value & (1U << (j % 32))) != 0)
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

static int	_put_ranks(t_psstacks **stacks)
{
	int	n;

	n = cdlst_len((*stacks)->stack_a);
	//presort_stacks(stacks);
	push_all_to_stack_a(stacks);
	//radix_sort_stacks_32th_bit(stacks, n);
	//radix_sort_stacks(stacks, n);
	radix_sort_stacks_X(stacks, n);
	set_rank_for_sorted(stacks);
	reverse_sorted(stacks);
	delete_cdlst(&((*stacks)->stack_ops));
	free((*stacks)->a_ops);
	free((*stacks)->b_ops);
	(*stacks)->stack_ops = ft_cdlstinit();
	(*stacks)->op_count = 0;
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
	_put_ranks(&stacks);
	push_all_to_stack_a(&stacks);
	radix_sort_stacks2(&stacks, argc - 1);
	print_sort_ops(&stacks);
	free_stacks(&stacks);
	return (0);
}


