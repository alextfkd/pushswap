/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:42:48 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/15 17:58:41 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_psstacks **stacks)
{
	delete_cdlst(&((*stacks)->stack_a));
	delete_cdlst(&((*stacks)->stack_b));
	delete_cdlst(&((*stacks)->stack_ops));
	free(*stacks);
}
