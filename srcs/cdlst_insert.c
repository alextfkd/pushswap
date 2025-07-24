/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:22:19 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/22 16:48:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Insert new_next node between nil and nil->next.
// Before: nil->old_next
// After: nil->new_next->old_next
int	insert_nil_next(t_cdlist **lst, t_cdlist *new_next)
{
	t_cdlist	*nil;
	t_cdlist	*old_next;

	nil = cdlst_find_nil(*lst);
	if (nil == NULL)
		return (1);
	old_next = nil->next;
	nil->next = new_next;
	old_next->prev = new_next;
	new_next->prev = nil;
	new_next->next = old_next;
	return (0);
}

// Insert new_prev node between nil and nil->prev.
// Before: old_prev->nil
// After: old_prev->new_prev->nil
int	insert_nil_prev(t_cdlist **lst, t_cdlist *new_prev)
{
	t_cdlist	*nil;
	t_cdlist	*old_prev;

	nil = cdlst_find_nil(*lst);
	if (nil == NULL)
		return (1);
	old_prev = nil->prev;
	nil->prev = new_prev;
	old_prev->next = new_prev;
	new_prev->prev = old_prev;
	new_prev->next = nil;
	return (0);
}

// Before: -> nil -> NODE_1 -> NODE_2 -> NODE_3 ->
// After: -> nil -> NODE_2 -> NODE_1 -> NODE_3 ->
int	swap_forward(t_cdlist **lst)
{
	t_cdlist	*nil;
	t_cdlist	*next_1;
	t_cdlist	*next_2;
	t_cdlist	*next_3;

	nil = cdlst_find_nil(*lst);
	if (nil == NULL)
		return (1);
	next_1 = nil->next;
	next_2 = nil->next->next;
	next_3 = nil->next->next->next;
	nil->next = next_2;
	next_2->next = next_1;
	next_2->prev = nil;
	next_1->next = next_3;
	next_1->prev = next_2;
	next_3->prev = next_1;
	return (0);
}

// Before: -> NODE_3 -> NODE_2 -> NODE_1 -> nil
// After: -> NODE_3 -> NODE_1 -> NODE_2 -> nil
int	swap_backward(t_cdlist **lst)
{
	t_cdlist	*nil;
	t_cdlist	*prev_1;
	t_cdlist	*prev_2;
	t_cdlist	*prev_3;

	nil = cdlst_find_nil(*lst);
	if (nil == NULL)
		return (1);
	prev_1 = nil->prev;
	prev_2 = nil->prev->prev;
	prev_3 = nil->prev->prev->prev;
	nil->prev = prev_2;
	prev_2->next = nil;
	prev_2->prev = prev_1;
	prev_1->next = prev_2;
	prev_1->prev = prev_3;
	prev_3->next = prev_1;
	return (0);
}
