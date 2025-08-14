/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:32:33 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/14 21:59:09 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_single_node(t_cdlist *node)
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

// Delete and free entire circulated list.
void	delete_cdlst(t_cdlist **lst)
{
	t_cdlist	*current;
	t_cdlist	*nil;
	t_cdlist	*tmp;

	if (lst == NULL || (*lst) == NULL)
		return ;
	nil = cdlst_find_nil(*lst);
	if (nil == NULL)
		return ;
	current = nil->next;
	while (current != nil)
	{
		tmp = current;
		current = current->next;
		del_single_node(tmp);
	}
	del_single_node(nil);
	*lst = NULL;
}
