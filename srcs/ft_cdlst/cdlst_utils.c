/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:10:37 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/14 21:58:51 by tkatsuma         ###   ########.fr       */
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

void	free_cdlst_node(t_cdlist *lst)
{
	t_cdlist	*nil;
	t_cdlist	*ptr;
	t_cdlist	*temp;

	nil = cdlst_find_nil(lst);
	ptr = nil->prev;
	while (ptr != nil)
	{
		temp = ptr;
		ptr = temp->prev;
		temp->next = NULL;
		temp->prev = NULL;
		free (temp->content);
		free (temp);
	}
	free (nil);
}

int	cmp_cdlst(t_cdlist	*stack_1, t_cdlist *stack_2)
{
	t_cdlist	*n1;
	t_cdlist	*n2;
	t_cdlist	*s1;
	t_cdlist	*s2;

	if (stack_1 == NULL || stack_2 == NULL)
		return (0);
	n1 = cdlst_find_nil(stack_1);
	n2 = cdlst_find_nil(stack_2);
	s1 = n1->next;
	s2 = n2->next;
	while (s1 != n1 && s2 != n2)
	{
		if (s1->content->value != s2->content->value)
			return (0);
		s1 = s1->next;
		s2 = s2->next;
	}
	if (s1 == n1 && s2 == n2)
		return (1);
	return (0);
}

int	cdlst_len(t_cdlist *lst)
{
	int			len;
	t_cdlist	*nil;
	t_cdlist	*node;

	len = 0;
	if (lst == NULL)
		return (-1);
	nil = cdlst_find_nil(lst);
	node = nil->next;
	while (node != nil)
	{
		node = node->next;
		len++;
	}
	return (len);
}
