/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:25:19 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/14 22:14:37 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cdlist_count_sorted(t_cdlist *lst)
{
	t_cdlist	*nil;
	t_cdlist	*ptr;
	int			count;

	nil = cdlst_find_nil(lst);
	ptr = nil->next;
	if (ptr == nil)
		return (0);
	count = 1;
	if (ptr->next->content == NULL)
		return (count);
	if (ptr->content->value < ptr->next->content->value)
	{
		while (ptr->content->value < ptr->next->content->value)
		{
			count++;
			ptr = ptr->next;
			if (ptr->next->content == NULL)
				break ;
		}
		return (count);
	}
	while (ptr->content->value > ptr->next->content->value)
	{
		count++;
		ptr = ptr->next;
		if (ptr->next->content == NULL)
			break ;
	}
	return (count);
}
