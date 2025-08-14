/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:30:49 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 00:43:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# define DEBUG 0

# define STACK_A -1
# define STACK_B 1

# define INVALID_NODE 0
# define VALID_NODE 1
# define NIL_NODE 2
# define FREE_NODE 3

# define MAX_ERRNO 100
# define FT_ENOENT 2
# define FT_EIO 5
# define FT_EOVERFLOW 84
# define MSG_ENOENT "Invalid arg count."
# define MSG_EIO "Invalid input."
# define MSG_EOVERFLOW "Numerical overflow in arguments."


# define ORDER_0 0
# define ORDER_1 1
# define ORDER_12 12
# define ORDER_21 21
# define ORDER_123 123
# define ORDER_132 132
# define ORDER_213 213
# define ORDER_231 231
# define ORDER_312 312
# define ORDER_321 321

#define SORT_ASC 1
#define SORT_NO 0
#define SORT_DESC -1

#define ORDER_ASC 1
#define ORDER_DESC -1

#define PUSH_A2B 1
#define PUSH_B2A -1

#define SA 2
#define SB -2
#define SS 20
#define PA 1
#define PB -1
#define RA 3
#define RRA -3
#define RB 4
#define RRB -4
#define RR 5
#define RRR -5

typedef	struct	s_psdata
{
	int	value;
	int	rank;
}	t_psdata;

typedef struct	s_cdlist
{
	struct s_psdata	*content;
	struct s_cdlist	*next;
	struct s_cdlist	*prev;
}	t_cdlist;

typedef struct s_psstacks
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;
	t_cdlist	*stack_ops;
	char		*a_ops;
	char		*b_ops;
	int			op_count;
	int			status;
	int			a_sort_len;
	int			b_sort_len;
}	t_psstacks;

int	validate_args(int argc, char **argv);
int	ft_perror(int err_code);

t_cdlist	*ft_cdlstinit(void);
t_cdlist	*create_cdlst_node(const int value);

int			is_valid_node(t_cdlist *node);
t_cdlist	*cdlst_find_nil(t_cdlist *lst);
t_cdlist	*cdlst_find_head(t_cdlist *lst);
t_cdlist	*cdlst_find_tail(t_cdlist *lst);

int	insert_nil_next(t_cdlist **lst, t_cdlist *new_next);
int	insert_nil_prev(t_cdlist **lst, t_cdlist *new_prev);
int	rotate_forward(t_cdlist **lst);
int	rotate_backward(t_cdlist **lst);
int	swap_forward(t_cdlist **lst);
int	swap_backward(t_cdlist **lst);

void	print_cdlst(t_cdlist *lst, int stack);
void	print_stacks(t_psstacks *stacks);

t_cdlist	*pop_cdlstnode(t_cdlist	*node);
void		delete_cdlst(t_cdlist **lst);

int	push_to_a_stack(t_psstacks **stacks);
int	push_to_b_stack(t_psstacks **stacks);

t_psstacks	*init_stacks(int argc, char **argv);

int	w_pa(t_psstacks **stacks);
int	w_pb(t_psstacks **stacks);
int	w_sa(t_psstacks **stacks);
int	w_sb(t_psstacks **stacks);
int	w_ss(t_psstacks **stacks);
int	w_ra(t_psstacks **stacks);
int	w_rb(t_psstacks **stacks);
int	w_rr(t_psstacks **stacks);
int	w_rra(t_psstacks **stacks);
int	w_rrb(t_psstacks **stacks);
int	w_rrr(t_psstacks **stacks);

int		if_stack_a_sorted(t_psstacks *stacks);
int		if_stack_b_sorted(t_psstacks *stacks);
int	if_stacks_sorted(t_psstacks *stacks);

int	stack_top3_status(t_cdlist *stack);
int	do_ops(t_psstacks **stacks);
int	sort_top3_stacks(t_psstacks **stacks, int a_dir, int b_dir);

int	rotate_merge(
	t_psstacks **stacks,
	int order,
	int push_toward
);

int	rev_rotate_merge(
	t_psstacks **stacks,
	int r_count,
	int order,
	int push_toward
);
int	cdlist_count_sorted(t_cdlist *head);

t_cdlist	*create_stack_from_arr(int *arr, int len);
t_psstacks	*create_stacks_from_cdlist(t_cdlist *stack_a, t_cdlist *stack_b, t_cdlist *stack_ops);
void	free_cdlst_node(t_cdlist *lst);
int		cmp_cdlst(t_cdlist	*stack_1, t_cdlist *stack_2);
int	cdlst_len(t_cdlist *lst);
int	cmp_stacks(t_psstacks *stacks_1, t_psstacks *stacks_2);
int	w_pan(t_psstacks **stacks, int n);
int	w_pbn(t_psstacks **stacks, int n);
void	free_stacks(t_psstacks **stacks);
int	vsort_top3_stacks(t_psstacks **stack);
int	msort_top3_stacks(t_psstacks **stack);
int	asort_top3_stacks(t_psstacks **stack);
int	dsort_top3_stacks(t_psstacks **stack);
int	cdlist_count_sorted(t_cdlist *lst);
t_psstacks	*init_stacks_from_array(int *arr, int len);

int	top3_sort_test(void);
int	top2_sort_test(void);
int	test_vsort_top3(t_psstacks *sorted, int *arr, int len, int print);
int	test_msort_top3(t_psstacks *sorted, int *arr, int len, int print);
int	test_asort_top3(t_psstacks *sorted, int *arr, int len, int print);
int	test_dsort_top3(t_psstacks *sorted, int *arr, int len, int print);
int	test_vsort_top2(t_psstacks *sorted, int *arr, int len, int print);
int	test_msort_top2(t_psstacks *sorted, int *arr, int len, int print);
int	test_asort_top2(t_psstacks *sorted, int *arr, int len, int print);
int	test_dsort_top2(t_psstacks *sorted, int *arr, int len, int print);

#endif