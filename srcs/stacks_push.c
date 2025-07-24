/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:47:07 by marvin            #+#    #+#             */
/*   Updated: 2025/07/24 20:12:41 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_push_to_b_stack(t_cdlist *stack_a, t_cdlist *stack_b)
{
	t_cdlist	*node;

	node = cdlst_find_head(stack_a);
	node = pop_cdlstnode(node);
	if (node == NULL)
		return (1);
	stack_b = cdlst_find_head(stack_b);
	insert_nil_next(&stack_b, node);
	return (0);
}

static int	_push_to_a_stack(t_cdlist *stack_a, t_cdlist *stack_b)
{
	t_cdlist	*node;

	node = cdlst_find_tail(stack_b);
	node = pop_cdlstnode(node);
	if (node == NULL)
		return (1);
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
