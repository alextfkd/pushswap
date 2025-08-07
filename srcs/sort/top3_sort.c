/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:12:28 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/07 12:12:40 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vsort_top3_stacks(t_psstacks **stack)
{
	return (sort_top3_stacks(stack, ORDER_ASC, ORDER_ASC));
}

int	msort_top3_stacks(t_psstacks **stack)
{
	return (sort_top3_stacks(stack, ORDER_DESC, ORDER_DESC));
}

int	asort_top3_stacks(t_psstacks **stack)
{
	return (sort_top3_stacks(stack, ORDER_ASC, ORDER_DESC));
}

int	dsort_top3_stacks(t_psstacks **stack)
{
	return (sort_top3_stacks(stack, ORDER_DESC, ORDER_ASC));
}
