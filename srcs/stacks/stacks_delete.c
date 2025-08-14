/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:42:48 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/07 07:45:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_psstacks **stacks)
{
	delete_cdlst(&((*stacks)->stack_a));
	delete_cdlst(&((*stacks)->stack_b));
	free(*stacks);
}
