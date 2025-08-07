/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:42:48 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/07 05:22:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_psstacks **stacks)
{
	ft_printf("[1]");
	delete_cdlst((*stacks)->stack_a);
	ft_printf("[2]");
	delete_cdlst((*stacks)->stack_b);
	ft_printf("[3]");
	free(*stacks);
	ft_printf("[4]\n");
}
