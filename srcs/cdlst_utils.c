/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:10:37 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/24 18:27:16 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// STACK_A (-1): Print from nil->prev (backward).
// STACK_B (1): Print from nil->next (forward).
void	print_cdlst(t_cdlist *lst, int stack)
{
	t_cdlist	*nil;
	t_cdlist	*ptr;

	nil = cdlst_find_nil(lst);
	if (stack == STACK_A)
	{
		ft_printf("A ");
		ptr = nil->prev;
		while (ptr->content != NULL)
		{
			ft_printf("%d ", ptr->content->value);
			ptr = ptr->prev;
		}
	}
	if (stack == STACK_B)
	{
		ptr = nil->next;
		while (ptr->content != NULL)
		{
			ft_printf("%d ", ptr->content->value);
			ptr = ptr->next;
		}
		ft_printf("B");
	}
}

static void	_print_stacks(t_cdlist *stack_a, t_cdlist *stack_b)
{
	print_cdlst(stack_a, STACK_A);
	ft_printf("| ");
	print_cdlst(stack_b, STACK_B);
	ft_printf("\n");
}

void	print_stacks(t_psstacks *stacks)
{
	_print_stacks(stacks->stack_a, stacks->stack_b);
}
