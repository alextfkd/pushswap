/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_from_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:46:33 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/14 22:13:09 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*del_if_exists(
	t_cdlist	**stack_a,
	t_cdlist	**stack_b,
	t_cdlist	**stack_ops
)
{
	if (stack_a != NULL)
		delete_cdlst(stack_a);
	if (stack_b != NULL)
		delete_cdlst(stack_b);
	if (stack_ops != NULL)
		delete_cdlst(stack_ops);
	return (NULL);
}

t_psstacks	*init_stacks_from_array(int *arr, int len)
{
	t_psstacks	*stacks;
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;
	t_cdlist	*stack_ops;

	if (arr == NULL || len <= 0)
		return (NULL);
	stack_a = create_stack_from_arr(arr, len);
	if (stack_a == NULL)
		return (NULL);
	stack_b = ft_cdlstinit();
	if (stack_b == NULL)
		return (delete_cdlst(&stack_a));
	stack_ops = ft_cdlstinit();
	if (stack_ops == NULL)
	{
		delete_cdlst(&stack_a);
		delete_cdlst(&stack_b);
		return (NULL);
	}
	stacks = create_stacks_from_cdlist(stack_a, stack_b, stack_ops);
	if (stacks == NULL)
		return (del_if_exists(&stack_a, &stack_b, &stack_ops));
	return (stacks);
}
