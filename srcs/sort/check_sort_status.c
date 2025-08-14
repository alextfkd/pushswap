/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:01:28 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 08:17:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int _stack_top_2_status(t_cdlist *stack)
{
	t_cdlist	*top;
	int			topv;
	int			topnv;

	top = cdlst_find_head(stack);
	topv = top->content->value;
	topnv = top->next->content->value;
	if (top->next->next->content == NULL && topv > topnv)
		return (ORDER_21);
	else if (top->next->next->content == NULL && topv < topnv)
		return (ORDER_12);
	else
		return (-1);
}

static int _stack_top_3_status(t_cdlist *stack)
{
	t_cdlist	*top;
	int			topv;
	int			topnv;
	int			topnnv;

	top = cdlst_find_head(stack);
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
	else
		return (-1);
}


// Returns 3 digit num.
// top-value rank / next-value rank / next-next-value rank
// Ex: nil->10->3->4 => "312"
int	stack_top3_status(t_cdlist *stack)
{
	int			listlen;

	listlen = cdlst_len(stack);
	if (listlen == 0)
		return (ORDER_0);
	else if (listlen == 1)
		return (ORDER_1);
	else if (listlen == 2)
		return (_stack_top_2_status(stack));
	else if (listlen >= 3)
		return (_stack_top_3_status(stack));
	else
		return (-1);
}
