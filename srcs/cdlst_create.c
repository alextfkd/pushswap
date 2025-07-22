/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlst_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:23:23 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/22 21:44:56 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_psdata	*_create_psdata(const int value, int rank)
{
	t_psdata	*data;

	data = (t_psdata *)malloc(sizeof(t_psdata));
	if (data == NULL)
		return (NULL);
	data->value = value;
	data->rank = rank;
	return (data);
}

static t_cdlist	*_create_cdlist_node(t_psdata *data)
{
	t_cdlist	*node;

	node = (t_cdlist *)malloc(sizeof(t_cdlist));
	if (node == NULL)
		return (NULL);
	node->content = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// Create an initial nil node for
// a new circulating double-direction list.
t_cdlist	*ft_cdlstinit(void)
{
	t_cdlist	*nil;

	nil = _create_cdlist_node(NULL);
	if (nil == NULL)
		return (NULL);
	nil->content = NULL;
	nil->next = nil;
	nil->prev = nil;
	return (nil);
}

// Create an independent cdlst node.
// CAUTION: content->rank is initialized with -1.
t_cdlist	*create_cdlst_node(const int value)
{
	t_psdata	*data;
	t_cdlist	*node;

	data = _create_psdata(value, -1);
	if (data == NULL)
		return (NULL);
	node = _create_cdlist_node(data);
	if (node == NULL)
	{
		free (data);
		return (NULL);
	}
	return (node);
}
