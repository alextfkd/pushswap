/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:20:03 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/25 23:04:06 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_b2a_rev_rotate_merge_asc(t_psstacks **stacks, int r_count)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;

	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	while (r_count > 0)
	{
		if (b_head->content == NULL)
		{
			w_rra(stacks);
			r_count--;
		}
		else if (a_head->prev->prev->content->value < b_head->content->value)
			w_pa(stacks);
		else
		{
			w_rra(stacks);
			r_count--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	return (0);
}

static int	_a2b_rev_rotate_merge_asc(t_psstacks **stacks, int r_count)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;

	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	while (r_count > 0)
	{
		if (a_head->content == NULL)
		{
			ft_printf("[1]");
			w_rrb(stacks);
			r_count--;
		}
		else if (b_head->prev->prev->content->value > a_head->content->value)
		{
			ft_printf("[2]");
			w_pb(stacks);
		}
		else
		{
			ft_printf("[3]");
			w_rrb(stacks);
			r_count--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	return (0);
}

static int	_b2a_rev_rotate_merge_desc(t_psstacks **stacks, int r_count)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;

	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	while (r_count > 0)
	{
		if (b_head->content == NULL)
		{
			w_rra(stacks);
			r_count--;
		}
		else if (a_head->prev->prev->content->value > b_head->content->value)
			w_pa(stacks);
		else
		{
			w_rra(stacks);
			r_count--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	return (0);
}

static int	_a2b_rev_rotate_merge_desc(t_psstacks **stacks, int r_count)
{
	t_cdlist	*a_head;
	t_cdlist	*b_head;

	a_head = cdlst_find_head((*stacks)->stack_a);
	b_head = cdlst_find_head((*stacks)->stack_b);
	while (r_count > 0)
	{
		if (a_head->content == NULL)
		{
			w_rrb(stacks);
			r_count--;
		}
		else if (b_head->prev->prev->content->value > a_head->content->value)
			w_pb(stacks);
		else
		{
			w_rrb(stacks);
			r_count--;
		}
		a_head = cdlst_find_head((*stacks)->stack_a);
		b_head = cdlst_find_head((*stacks)->stack_b);
	}
	return (0);
}

int	rev_rotate_merge(
	t_psstacks **stacks,
	int r_count,
	int order,
	int push_toward
)
{
	if (order == ORDER_ASC && push_toward == PUSH_B2A)
	{
		ft_printf("rr1\n");
		return (_b2a_rev_rotate_merge_asc(stacks, r_count));
	}
	else if (order == ORDER_DESC && push_toward == PUSH_B2A)
	{
		ft_printf("rr2\n");
		return (_b2a_rev_rotate_merge_desc(stacks, r_count));
	}
	else if (order == ORDER_ASC && push_toward == PUSH_A2B)
	{
		ft_printf("rr3\n");
		return (_a2b_rev_rotate_merge_asc(stacks, r_count));
	}
	else if (order == ORDER_DESC && push_toward == PUSH_A2B)
	{
		ft_printf("rr4\n");
		return (_a2b_rev_rotate_merge_desc(stacks, r_count));
	}
	return (1);
}
