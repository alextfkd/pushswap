/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:47:07 by marvin            #+#    #+#             */
/*   Updated: 2025/08/18 00:31:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_push_to_b_stack(t_psstacks **stacks)
{
	t_cdlist	*head;
	t_cdlist	*node;

	head = cdlst_find_head((*stacks)->stack_a);
	if (head == NULL)
		return (1);
	node = pop_cdlstnode(head);
	if (node == NULL)
		return (1);
	return (insert_nil_next(&((*stacks)->stack_b), node));
}

static int	_push_to_a_stack(t_psstacks **stacks)
{
	t_cdlist	*head;
	t_cdlist	*node;

	head = cdlst_find_head((*stacks)->stack_b);
	if (head == NULL)
		return (1);
	node = pop_cdlstnode(head);
	if (node == NULL)
		return (1);
	return (insert_nil_next(&((*stacks)->stack_a), node));
}

int	push_to_b_stack(t_psstacks **stacks)
{
	return (_push_to_b_stack(stacks));
}

int	push_to_a_stack(t_psstacks **stacks)
{
	return (_push_to_a_stack(stacks));
}
