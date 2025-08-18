/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 20:08:13 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix_sort_stacks(t_psstacks **stacks, int n)
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
		print_stacks(*stacks);
		push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1)
			break ;
		j++;
	}
	return (0);
}

static int	compress_cordinates(t_psstacks **stacks)
{
	int	n;

	n = cdlst_len((*stacks)->stack_a);
	push_all_to_stack_a(stacks);
	naive_radix_sort(stacks, n);
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
		split_argv(&argc, &argv);
	status += validate_args(argc, argv);
	if (status > 0)
	{
		ft_perror(status);
		exit(status);
	}
	stacks = init_stacks(argc, argv);
	compress_cordinates(&stacks);
	push_all_to_stack_a(&stacks);
	radix_sort_stacks(&stacks, argc - 1);
	print_sort_ops(&stacks);
	free_stacks(&stacks);
	return (0);
}
