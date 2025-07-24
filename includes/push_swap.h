/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:30:49 by marvin            #+#    #+#             */
/*   Updated: 2025/07/22 16:38:17 by marvin           ###   ########.fr       */
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
void	print_stacks(t_cdlist *stack_a, t_cdlist *stack_b);

void	del_cdlstnode(t_cdlist *node);
t_cdlist	*pop_cdlstnode(t_cdlist	*node);
int	push_to_a_stack(t_cdlist *stack_a, t_cdlist *stack_b);
int	push_to_b_stack(t_cdlist *stack_a, t_cdlist *stack_b);

#endif