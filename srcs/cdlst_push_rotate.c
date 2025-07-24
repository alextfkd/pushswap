/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_push_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:47:07 by marvin            #+#    #+#             */
/*   Updated: 2025/07/24 19:01:04 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_push_to_b_stack(t_cdlist *stack_a, t_cdlist *stack_b)
{
	t_cdlist	*node;

	node = cdlst_find_head(stack_a);
	node = pop_cdlstnode(node);
	stack_b = cdlst_find_head(stack_b);
	insert_nil_next(&stack_b, node);
	return (0);
}

static int	_push_to_a_stack(t_cdlist *stack_a, t_cdlist *stack_b)
{
	t_cdlist	*node;

	node = cdlst_find_tail(stack_b);
	node = pop_cdlstnode(node);
	stack_a = cdlst_find_head(stack_a);
	insert_nil_next(&stack_a, node);
	return (0);
}

int	push_to_b_stack(t_psstacks **stacks)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	stack_a = (*stacks)->stack_a;
	stack_b = (*stacks)->stack_b;
	return (_push_to_b_stack(stack_a, stack_b));
}

int	push_to_a_stack(t_psstacks **stacks)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	stack_a = (*stacks)->stack_a;
	stack_b = (*stacks)->stack_b;
	return (_push_to_a_stack(stack_a, stack_b));
}

// Before: -> NODE_1 -> nil -> NODE_2 ->
// After: -> nil -> NODE_1 -> NODE_2 ->
int	rotate_forward(t_cdlist **lst)
{
	t_cdlist	*nil;
	t_cdlist	*new_next;

	nil = cdlst_find_nil(*lst);
	if (nil == NULL)
		return (1);
	new_next = pop_cdlstnode(nil->prev);
	if (new_next == NULL)
		return (1);
	return (insert_nil_next(lst, new_next));
}

// Before: -> NODE_1 -> nil -> NODE_2 ->
// After: -> NODE_1 -> NODE_2 -> nil ->
int	rotate_backward(t_cdlist **lst)
{
	t_cdlist	*nil;
	t_cdlist	*new_prev;

	nil = cdlst_find_nil(*lst);
	if (nil == NULL)
		return (1);
	new_prev = pop_cdlstnode(nil->next);
	if (new_prev == NULL)
		return (1);
	return (insert_nil_next(lst, new_prev));
}
