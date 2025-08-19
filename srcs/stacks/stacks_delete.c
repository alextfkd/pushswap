/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:42:48 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/08/19 09:13:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_psstacks **stacks)
{
	if (stacks == NULL)
		return ;
	if (*stacks == NULL)
		return ;
	delete_cdlst(&((*stacks)->stack_a));
	delete_cdlst(&((*stacks)->stack_b));
	delete_cdlst(&((*stacks)->stack_ops));
	free(*stacks);
}

int	close_main(
	t_psstacks **stacks,
	int sflag,
	char ***argv
)
{
	int	i;

	i = 0;
	free_stacks(stacks);
	if (sflag == 1)
	{
		while ((*argv)[i] != NULL)
			free ((*argv)[i++]);
		free(*argv);
	}
	return (0);
}
