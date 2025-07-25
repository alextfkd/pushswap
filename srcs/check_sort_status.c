/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:01:28 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 21:30:34 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_if_node_null(t_cdlist *top)
{
	if (top == NULL || top->next == NULL || top->next->next == NULL)
		return (1);
	return (0);
}

static int	_if_node_nil(t_cdlist *top)
{
	if (top->content == NULL)
		return (1);
	if (top->next->content == NULL)
		return (1);
	if (top->next->next->content == NULL)
		return (1);
	return (0);
}

// Returns 3 digit num.
// top-value rank / next-value rank / next-next-value rank
// Ex: nil->10->3->4 => "312"
int	stack_top3_status(t_cdlist *stack)
{
	t_cdlist	*top;
	int			topv;
	int			topnv;
	int			topnnv;

	top = cdlst_find_head(stack);
	if (_if_node_null(top) == 1 || _if_node_nil(top) == 1)
		return (1);
	topv = top->content->value;
	topnv = top->next->content->value;
	topnnv = top->next->next->content->value;
	if (topv < topnv && topnv < topnnv)
		return (ORDER_123);
	else if (topv < topnnv && topnnv < topnv)
		return (ORDER_132);
	else if (topnv < topv && topv < topnnv)
		return (ORDER_213);
	else if (topnv < topnnv && topnnv < topv)
		return (ORDER_312);
	else if (topnnv < topv && topv < topnv)
		return (ORDER_231);
	else if (topnnv < topnv && topnv < topv)
		return (ORDER_321);
	return (0);
}
