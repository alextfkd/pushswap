/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 06:53:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_len_1_2_3(t_psstacks **stacks)
{
	int			status;
	int			len;
	t_cdlist	*head;

	status = 0;
	len = cdlst_len((*stacks)->stack_a);
	if (len == 1)
	{
		return (status);
	}
	else if (len == 2)
	{
		head = cdlst_find_head((*stacks)->stack_a);
		if (head->content->value > head->next->content->value)
			status += w_sa(stacks);
		return (status);
	}
	else if (len == 3)
	{
		status += sort_top3_stacks(stacks, SORT_ASC, SORT_DESC);
		status += do_ops(stacks);
		return (status);
	}
	else
		return (1);
}

static int	sort_len_4_5_6(t_psstacks **stacks)
{
	int			status;
	int			i;
	int			len;
	t_cdlist	*head;

	status = 0;
	len = cdlst_len((*stacks)->stack_a);
	head = cdlst_find_head((*stacks)->stack_a);
	i = 0;
	while (i < len)
	{
		if (head ->content->value < len - 3)
			status += w_pb(stacks);
		else
			status += w_ra(stacks);
		head = cdlst_find_head((*stacks)->stack_a);
		i++;
	}
	status += sort_top3_stacks(stacks, SORT_ASC, SORT_DESC);
	status += do_ops(stacks);
	status += w_pan(stacks, len - 3);
	return (status);
}

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
		push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1)
			break ;
		j++;
	}
	return (0);
}

static int	_sort_stacks(int *status, int argc, t_psstacks **stacks)
{
	if (stacks == NULL || *stacks == NULL)
		return (*status);
	*status += compress_cordinates(stacks);
	if (argc == 2 || argc == 3 || argc == 4)
		*status += sort_len_1_2_3(stacks);
	else if (argc == 5 || argc == 6 || argc == 7)
		*status += sort_len_4_5_6(stacks);
	else
	{
		if (if_stack_a_sorted(*stacks) == 0)
			*status += radix_sort_stacks(stacks, argc - 1);
		else if ((*stacks)->stack_a->next->content->value != 0)
			*status += radix_sort_stacks(stacks, argc - 1);
		else
			return (*status);
	}
	return (*status);
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
	status += _sort_stacks(&status, argc, &stacks);
	if (status > 0)
	{
		ft_perror(status);
		free_stacks(&stacks);
		exit(status);
	}
	print_sort_ops(&stacks);
	free_stacks(&stacks);
	return (0);
}
