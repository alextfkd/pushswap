/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:23:00 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/24 18:23:21 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_psstacks	*create_stacks(void)
{
	t_psstacks	*stacks;

	stacks = (t_psstacks *)malloc(sizeof(t_psstacks));
	if (stacks == NULL)
		return (NULL);
	stacks->stack_a = ft_cdlstinit();
	stacks->stack_b = ft_cdlstinit();
	stacks->op_count = 0;
	stacks->status = 0;
	return (stacks);
}
