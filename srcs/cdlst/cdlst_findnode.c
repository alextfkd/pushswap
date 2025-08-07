/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_findnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:43:36 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/22 22:39:52 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define INVALID_NODE 0
#define VALID_NODE 1
#define NIL_NODE 2
#define FREE_NODE 3

// Return 0 (INVALID_NODE) if the node is invalid.
// Return 1 (VALID_NODE) if the node is a valid node (data node).
// Return 2 (NIL_NODE) if the node is a valid node (nil node).
// Return 3 (FREE_NODE) if the node is a valid node (free node).
int	is_valid_node(t_cdlist *node)
{
	if (node == NULL)
		return (INVALID_NODE);
	if (node->content != NULL && node->next == NULL && node->prev == NULL)
		return (FREE_NODE);
	if (node->content == NULL && node->next != NULL && node->prev != NULL)
		return (NIL_NODE);
	if (node->content != NULL && node->next != NULL && node->prev != NULL)
		return (VALID_NODE);
	return (INVALID_NODE);
}

// Find initial nil node pointer.
// Return NULL if error.
t_cdlist	*cdlst_find_nil(t_cdlist *lst)
{
	t_cdlist	*ptr;
	int			type;

	type = is_valid_node(lst);
	if (type == NIL_NODE)
		return (lst);
	else if (type == INVALID_NODE || type == FREE_NODE)
		return (NULL);
	ptr = lst;
	while (is_valid_node(ptr) != NIL_NODE)
		ptr = ptr->next;
	return (ptr);
}

// Find nil->next node pointer.
// Returns NULL if error.
// Returns nil node if there is only one node (nil) in the list.
t_cdlist	*cdlst_find_head(t_cdlist *lst)
{
	t_cdlist	*ptr;

	ptr = cdlst_find_nil(lst);
	if (ptr == NULL)
		return (NULL);
	return (ptr->next);
}

// Find nil->prev node pointer.
// Returns NULL if error.
// Returns nil node if there is only one node (nil) in the list.
t_cdlist	*cdlst_find_tail(t_cdlist *lst)
{
	t_cdlist	*ptr;

	ptr = cdlst_find_nil(lst);
	if (ptr == NULL)
		return (NULL);
	return (ptr->prev);
}
