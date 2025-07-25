/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:23:00 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/07/25 05:17:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_psstacks	*_create_stacks(void)
{
	t_psstacks	*stacks;

	stacks = (t_psstacks *)malloc(sizeof(t_psstacks));
	if (stacks == NULL)
		return (NULL);
	stacks->stack_a = ft_cdlstinit();
	stacks->stack_b = ft_cdlstinit();
	stacks->a_ops = NULL;
	stacks->b_ops = NULL;
	stacks->op_count = 0;
	stacks->status = 0;
	return (stacks);
}

static int	*_create_argv_int_array(int argc, char **argv)
{
	int	*arr;
	int	i;

	i = 1;
	if (argc <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (arr == NULL)
		return (NULL);
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (arr);
}

// STACK A | nil -> (top) -> (top -1) -> ... -> (last) -> (nil)
static int	_load_args_to_stack_a(int *arr, int len, t_psstacks **stacks)
{
	int			i;
	int			status;
	t_cdlist	*node;

	i = 0;
	status = 0;
	while (i < len)
	{
		//ft_printf("arr[%d] = %d\n", i, arr[i]);
		node = create_cdlst_node(arr[i]);
		status = insert_nil_prev(&((*stacks)->stack_a), node);
		if (status > 0)
			return (1);
		i++;
	}
	return (0);
}

// STACK A | nil -> (top) -> (top -1) -> ... -> (last) -> (nil)
// STACK B | nil -> (top) -> (top -1) -> ... -> (last) -> (nil)
t_psstacks	*init_stacks(int argc, char **argv)
{
	t_psstacks	*stacks;
	int			*arr;
	int			status;

	stacks = _create_stacks();
	if (stacks == NULL)
		return (NULL);
	arr = _create_argv_int_array(argc, argv);
	if (arr == NULL)
	{
		free (arr);
		return (NULL);
	}
	status = _load_args_to_stack_a(arr, argc - 1, &stacks);
	free (arr);
	if (status == 1)
	{
		free(stacks);
		return (NULL);
	}
	return (stacks);
}
