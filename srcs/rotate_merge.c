/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:10:26 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/25 23:00:58 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_a2b_rotate_merge_desc(t_psstacks **stacks, int sorted_count)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;

	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	r_count = 0;
	while (a_head->content != NULL && sorted_count > 0)
	{
		print_stacks(*stacks);
		if (b_head->content->value > a_head->content->value)
		{
			w_rb(stacks);
			r_count++;
		}
		else
		{
			w_pb(stacks);
			sorted_count--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	return (r_count);
}

static int	_b2a_rotate_merge_asc(t_psstacks **stacks, int sorted_count)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;

	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	r_count = 0;
	while (b_head->content != NULL && sorted_count > 0)
	{
		print_stacks(*stacks);
		if (a_head->content->value > b_head->content->value)
		{
			w_ra(stacks);
			r_count++;
		}
		else
		{
			w_pa(stacks);
			sorted_count--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	return (r_count);
}

static int	_a2b_rotate_merge_asc(t_psstacks **stacks, int sorted_count)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;
	int			i;
	int			rlim;

	i = 0;
	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);

	rlim = cdlist_count_sorted(b_head);
	ft_printf("rlim: %d", rlim);
	r_count = 0;
	while (a_head->content != NULL && sorted_count > 0)
	{
		ft_printf("a");
		print_stacks(*stacks);
		if (rlim == 0)
		{
			ft_printf("X");
			w_pb(stacks);
			sorted_count--;
		}
		else if (b_head->content->value > a_head->content->value)
		{
			w_rb(stacks);
			rlim--;
			r_count++;
		}
		else
		{
			w_pb(stacks);
			w_rb(stacks);
			r_count++;
			sorted_count--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	ft_printf("rcount: %d", r_count);
	return (r_count);
}

static int	_b2a_rotate_merge_desc(t_psstacks **stacks, int sorted_count)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;

	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	r_count = 0;
	while (b_head->content != NULL && sorted_count > 0)
	{
		print_stacks(*stacks);
		if (a_head->content->value < b_head->content->value)
		{
			w_ra(stacks);
			r_count++;
		}
		else
		{
			w_pa(stacks);
			sorted_count--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	return (r_count);
}

int	rotate_merge(
	t_psstacks **stacks,
	int sorted_count,
	int order,
	int push_toward
)
{
	if (order == ORDER_ASC && push_toward == PUSH_B2A)
		return (_b2a_rotate_merge_asc(stacks, sorted_count));
	else if (order == ORDER_DESC && push_toward == PUSH_B2A)
		return (_b2a_rotate_merge_desc(stacks, sorted_count));
	else if (order == ORDER_ASC && push_toward == PUSH_A2B)
		return (_a2b_rotate_merge_asc(stacks, sorted_count));
	else if (order == ORDER_DESC && push_toward == PUSH_A2B)
		return (_a2b_rotate_merge_desc(stacks, sorted_count));
	return (1);
}
