/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:10:26 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/29 16:08:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_a2b_rotate_merge_asc(t_psstacks **stacks)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;

	ft_printf("A2B-ASC, a_sort_ren=%d \n", (*stacks)->a_sort_len);
	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	r_count = 0;
	while (a_head->content != NULL && (*stacks)->a_sort_len > 0)
	{
		print_stacks(*stacks);
		if ((*stacks)->b_sort_len == 0)
		{
			ft_printf("[p1: ] ");
			w_pb(stacks);
			w_rb(stacks);
			(*stacks)->a_sort_len--;
			r_count++;
		}
		else if (a_head->content->value > b_head->content->value)
		{
			ft_printf("[p2: ] ");
			w_rb(stacks);
			(*stacks)->b_sort_len--;
			r_count++;
		}
		else
		{
			ft_printf("[p3: ] ");
			w_pb(stacks);
			w_rb(stacks);
			r_count++;
			(*stacks)->a_sort_len--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	ft_printf("rcount: %d", r_count);
	return (r_count);
}

static int	_b2a_rotate_merge_asc(t_psstacks **stacks)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;

	ft_printf("B2A-ASC, a_sort_ren=%d \n", (*stacks)->b_sort_len);
	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	r_count = 0;
	while (b_head->content != NULL && (*stacks)->b_sort_len > 0)
	{
		print_stacks(*stacks);
		if ((*stacks)->a_sort_len == 0)
		{
			ft_printf("[p1: ] ");
			w_pa(stacks);
			w_ra(stacks);
			(*stacks)->b_sort_len--;
			r_count++;
		}
		else if (b_head->content->value > a_head->content->value)
		{
			ft_printf("[p2: ] ");
			w_ra(stacks);
			(*stacks)->a_sort_len--;
			r_count++;
		}
		else
		{
			ft_printf("[p3: ] ");
			w_pa(stacks);
			w_ra(stacks);
			r_count++;
			(*stacks)->b_sort_len--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	ft_printf("rcount: %d", r_count);
	return (r_count);
}

static int	_b2a_rotate_merge_desc(t_psstacks **stacks)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;

	ft_printf("B2A-ASC, a_sort_ren=%d \n", (*stacks)->b_sort_len);
	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	r_count = 0;
	while (b_head->content != NULL && (*stacks)->b_sort_len > 0)
	{
		print_stacks(*stacks);
		if ((*stacks)->a_sort_len == 0)
		{
			ft_printf("[p1: ] ");
			w_pa(stacks);
			w_ra(stacks);
			(*stacks)->b_sort_len--;
			r_count++;
		}
		else if (b_head->content->value < a_head->content->value)
		{
			ft_printf("[p2: ] ");
			w_ra(stacks);
			(*stacks)->a_sort_len--;
			r_count++;
		}
		else
		{
			ft_printf("[p3: ] ");
			w_pa(stacks);
			w_ra(stacks);
			r_count++;
			(*stacks)->b_sort_len--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	ft_printf("rcount: %d", r_count);
	return (r_count);
}


static int	_a2b_rotate_merge_desc(t_psstacks **stacks)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;

	ft_printf("A2B-DESC, a_sort_ren=%d \n", (*stacks)->a_sort_len);
	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	r_count = 0;
	while (a_head->content != NULL && (*stacks)->a_sort_len > 0)
	{
		print_stacks(*stacks);
		if ((*stacks)->b_sort_len == 0)
		{
			ft_printf("[p1: ] ");
			w_pb(stacks);
			w_rb(stacks);
			(*stacks)->a_sort_len--;
			r_count++;
		}
		else if (a_head->content->value < b_head->content->value)
		{
			ft_printf("[p2: ] ");
			w_rb(stacks);
			(*stacks)->b_sort_len--;
			r_count++;
		}
		else
		{
			ft_printf("[p3: ] ");
			w_pb(stacks);
			w_rb(stacks);
			r_count++;
			(*stacks)->a_sort_len--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	ft_printf("rcount: %d", r_count);
	return (r_count);
}

/*
static int	_a2b_rotate_merge_descold(t_psstacks **stacks)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;
	int			r_count;

	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	r_count = 0;
	while (a_head->content != NULL && (*stacks)->a_sort_len > 0)
	{
		print_stacks(*stacks);
		if ((*stacks)->b_sort_len == 0)
		{
			ft_printf("[p1: ] ");
			w_pb(stacks);
			(*stacks)->a_sort_len--;
		}
		else if (a_head->content->value < b_head->content->value)
		{
			ft_printf("[p2: ] ");
			w_rb(stacks);
			(*stacks)->b_sort_len--;
			r_count++;
		}
		else
		{
			ft_printf("[p3: ] ");
			w_pb(stacks);
			w_rb(stacks);
			r_count++;
			(*stacks)->a_sort_len--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	ft_printf("rcount: %d", r_count);
	return (r_count);
}
*/
/*

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

*/
int	rotate_merge(
	t_psstacks **stacks,
	int order,
	int push_toward
)
{
	if (order == ORDER_ASC && push_toward == PUSH_A2B)
		return (_a2b_rotate_merge_asc(stacks));
	if (order == ORDER_ASC && push_toward == PUSH_B2A)
		return (_b2a_rotate_merge_asc(stacks));
	else if (order == ORDER_DESC && push_toward == PUSH_B2A)
		return (_b2a_rotate_merge_desc(stacks));
	else if (order == ORDER_DESC && push_toward == PUSH_A2B)
		return (_a2b_rotate_merge_desc(stacks));
	return (1);
}
