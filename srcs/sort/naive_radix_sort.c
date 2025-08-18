/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_radix_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:38:04 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 00:14:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_radix_sort_stacks_32bit(t_psstacks **stacks, int n)
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
	}
	push_all_to_stack_a(stacks);
	return (0);
}

static int	_radix_sort_stacks_1to31bit(t_psstacks **stacks, int n)
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
			i++;
		}
		push_all_to_stack_a(stacks);
		j++;
	}
	return (0);
}

static int	_radix_sort_sub(t_psstacks **stacks, int j)
{
	t_cdlist	*top;

	top = cdlst_find_head((*stacks)->stack_a);
	if (top == NULL)
		return (1);
	if (((top->content->value & (1U << (j % 32))) != 0) && (j % 32 != 31))
		return (w_ra(stacks));
	else if (((top->content->value & (1U << (j % 32))) == 0) && (j % 32 != 31))
		return (w_pb(stacks));
	else if (((top->content->value & (1U << (j % 32))) != 0) && (j % 32 == 31))
		return (w_pb(stacks));
	else if (((top->content->value & (1U << (j % 32))) == 0) && (j % 32 == 31))
		return (w_ra(stacks));
	else
		return (1);
}

static int	_radix_sort_stacks(t_psstacks **stacks, int n)
{
	t_cdlist	*top;
	int			res;
	int			i;
	int			j;

	j = 31;
	res = 0;
	while (j < 64)
	{
		i = 0;
		while (i < n)
		{
			res += _radix_sort_sub(stacks, j);
			i++;
		}
		res += push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1)
			break ;
		j++;
	}
	return (res);
}

int	naive_radix_sort(t_psstacks **stacks, int n)
{
	return (_radix_sort_stacks(stacks, n));
}
