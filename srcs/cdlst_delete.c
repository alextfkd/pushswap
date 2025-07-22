/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:32:33 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/22 22:44:21 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_cdlstnode(t_cdlist *node)
{
	if (node == NULL)
		return ;
	if (node->content != NULL)
		free (node->content);
	free (node);
	return ;
}

// Free the valid node from the circulated list.
// Returns the freed node.
// If the node is either nil, invalid or free,
// the node will not be popped and returns NULL instead.
t_cdlist	*pop_cdlstnode(t_cdlist	*node)
{
	t_cdlist	*next;
	t_cdlist	*prev;

	if (is_valid_node(node) != 1)
		return (NULL);
	next = node->next;
	prev = node->prev;
	next->prev = prev;
	prev->next = next;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
