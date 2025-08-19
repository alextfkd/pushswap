/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 09:12:35 by marvin           ###   ########.fr       */
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
		return (status);
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
		free((*stacks)->a_ops);
		free((*stacks)->b_ops);
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
	free((*stacks)->a_ops);
	free((*stacks)->b_ops);
	status += w_pan(stacks, len - 3);
	return (status);
}

static int	radix_sort_stacks(t_psstacks **stacks, int n)
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
	int			split_flag;

	stacks = NULL;
	status = 0;
	split_flag = 0;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (argc == 2)
		split_flag = split_argv(&argc, &argv);
	status += validate_args(argc, argv);
	if (status == 0)
	{
		stacks = init_stacks(argc, argv);
		status += compress_cordinates(&stacks);
	}
	if (status == 0)
		status += _sort_stacks(&status, argc, &stacks);
	if (status == 0)
		print_sort_ops(&stacks);
	ft_perror(status);
	close_main(&stacks, split_flag, &argv);
	return (0);
}
