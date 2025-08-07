/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:47:07 by marvin            #+#    #+#             */
/*   Updated: 2025/07/30 02:10:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	_push_to_b_stack(t_cdlist *stack_a, t_cdlist *stack_b)

static int	_push_to_b_stack(t_psstacks **stacks)
{
	t_cdlist	*node;

	node = cdlst_find_head((*stacks)->stack_a);
	node = pop_cdlstnode(node);
	if (node == NULL)
		return (0);
	insert_nil_next(&((*stacks)->stack_b), node);
	return (1);
}

static int	_push_to_a_stack(t_psstacks **stacks)
{
	t_cdlist	*node;

	node = cdlst_find_head((*stacks)->stack_b);
	node = pop_cdlstnode(node);
	if (node == NULL)
		return (0);
	insert_nil_next(&((*stacks)->stack_a), node);
	return (1);
}

int	push_to_b_stack(t_psstacks **stacks)
{
	return (_push_to_b_stack(stacks));
}

int	push_to_a_stack(t_psstacks **stacks)
{
	return (_push_to_a_stack(stacks));
}
