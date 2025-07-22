/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:22:19 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/22 22:44:12 by tkatsuma         ###   ########.fr       */
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
