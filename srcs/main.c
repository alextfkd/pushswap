/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/14 22:47:59 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	presort_stacks(t_psstacks **stacks)
{
	int	i;
	int	arrlen;

	i = 0;
	arrlen = cdlst_len((*stacks)->stack_a) + cdlst_len((*stacks)->stack_b);
	while (i <= arrlen / 6)
	{
		w_pbn(stacks, 3);
		asort_top3_stacks(stacks);
		do_ops(stacks);
		w_pbn(stacks, 3);
		i++;
	}
	return (0);
}

int	push_all_to_stack_a(t_psstacks **stacks)
{
	while (cdlst_len((*stacks)->stack_b) > 0)
		w_pa(stacks);
	return (0);
}

int	radix_sort_stacks(t_psstacks **stacks, int n)
{
	t_cdlist	*top;
	int			i;
	int			j;

	i = 0;
	j = 31;
	while (j < 32 + 32)
	{
		i = 0;
		while (i < n)
		{
			top = cdlst_find_head((*stacks)->stack_a);
			if (((top->content->value & (1 << (j % 32))) != 0) && (j % 32 != 31))
				w_ra(stacks);
			else if (((top->content->value & (1 << (j % 32))) == 0) && (j % 32 != 31))
				w_pb(stacks);
			else if (((top->content->value & (1 << (j % 32))) != 0) && (j % 32 == 31))
				w_pb(stacks);
			else
				w_ra(stacks);
			i++;
		}
		push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1)
			break;
		j++;
	}
	return (0);
}

int	radix_sort_stacks2(t_psstacks **stacks, int n)
{
	t_cdlist	*top;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < n)
		{
			top = cdlst_find_head((*stacks)->stack_a);
			if ((top->content->value & (1 << j)) != 0)
				w_ra(stacks);
			else
				w_pb(stacks);
			i++;
		}
		push_all_to_stack_a(stacks);
		if (if_stack_a_sorted(*stacks) == 1)
			break ;
		j++;
	}
	return (0);
}

int	set_rank_for_sorted(t_psstacks **stacks)
{
	int			i;
	t_cdlist	*tmp;

	i = 0;
	tmp = cdlst_find_head((*stacks)->stack_a);
	while (tmp->content != NULL)
	{
		tmp->content->value = i++;
		tmp = tmp->next;
	}
	return (0);
}

void	reverse_sorted(t_psstacks **stacks)
{
	t_cdlist	*tmp;

	tmp = (*stacks)->stack_ops->next;
	while (tmp->content != NULL)
	{
		if (tmp->content->value == PA)
			w_pb(stacks);
		else if (tmp->content->value == PB)
			w_pa(stacks);
		else if (tmp->content->value == SA)
			w_sa(stacks);
		else if (tmp->content->value == SB)
			w_sb(stacks);
		else if (tmp->content->value == SS)
			w_ss(stacks);
		else if (tmp->content->value == RA)
			w_rra(stacks);
		else if (tmp->content->value == RB)
			w_rrb(stacks);
		else if (tmp->content->value == RR)
			w_rrr(stacks);
		else if (tmp->content->value == RRA)
			w_ra(stacks);
		else if (tmp->content->value == RRB)
			w_rb(stacks);
		else if (tmp->content->value == RRR)
			w_rr(stacks);
		else
			break ;
		tmp = tmp->next;
	}
}

int	print_sort_ops(t_psstacks **stacks)
{
	t_cdlist	*tmp;

	tmp = cdlst_find_tail((*stacks)->stack_ops);
	while (tmp->content != NULL)
	{
		if (tmp->content->value == PA)
			ft_printf("pa\n");
		else if (tmp->content->value == PB)
			ft_printf("pb\n");
		else if (tmp->content->value == SA)
			ft_printf("sa\n");
		else if (tmp->content->value == SB)
			ft_printf("sb\n");
		else if (tmp->content->value == SS)
			ft_printf("ss\n");
		else if (tmp->content->value == RA)
			ft_printf("ra\n");
		else if (tmp->content->value == RB)
			ft_printf("rb\n");
		else if (tmp->content->value == RR)
			ft_printf("rr\n");
		else if (tmp->content->value == RRA)
			ft_printf("rra\n");
		else if (tmp->content->value == RRB)
			ft_printf("rrb\n");
		else if (tmp->content->value == RRR)
			ft_printf("rrr\n");
		else
			break ;
		tmp = tmp->prev;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_psstacks	*stacks;
	int			status;

	if (argc == 1)
		return (0);
	status = 0;
	if (argc == 2)
	{
		char	**splitted;
		splitted = ft_split((const char *)argv[1], ' ');
		int argc2 = 1;
		while (splitted[argc2 - 1] != NULL)
		{
			argc2++;
		}
		int	i;
		i = 0;
		char	**newargv;
		newargv = (char **)ft_calloc(sizeof(char *), argc2 + 1);
		newargv[0] = ft_strdup(argv[0]);
		i++;
		while (i < argc2)
		{
			newargv[i] = ft_strdup(splitted[i - 1]);
			i++;
		}
		argv = newargv;
		argc = argc2;
	}
	status += validate_args(argc, argv);
	if (status > 0)
	{
		ft_printf("!!!!!!!!!!!!");
		ft_perror(status);
		exit(status);
	}
	stacks = init_stacks(argc, argv);
	int n = cdlst_len(stacks->stack_a);
	presort_stacks(&stacks);
	push_all_to_stack_a(&stacks);
	radix_sort_stacks(&stacks, n);

	set_rank_for_sorted(&stacks);
	reverse_sorted(&stacks);
	free(stacks->stack_ops);
	stacks->stack_ops = ft_cdlstinit();
	stacks->op_count = 0;
	free(stacks->a_ops);
	free(stacks->b_ops);
	push_all_to_stack_a(&stacks);
	radix_sort_stacks2(&stacks, n);
	print_sort_ops(&stacks);
	return (0);
}


