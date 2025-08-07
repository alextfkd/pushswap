/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:47:07 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 08:34:01 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Before: -> NODE_1 -> nil -> NODE_2 ->
// After: -> nil -> NODE_1 -> NODE_2 ->
int	rotate_backward(t_cdlist **lst)
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
int	rotate_forward(t_cdlist **lst)
{
	t_cdlist	*nil;
	t_cdlist	*new_prev;

	nil = cdlst_find_nil(*lst);
	if (nil == NULL)
		return (1);
	new_prev = pop_cdlstnode(nil->next);
	if (new_prev == NULL)
		return (1);
	return (insert_nil_prev(lst, new_prev));
}
