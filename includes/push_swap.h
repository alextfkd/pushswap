/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:30:49 by marvin            #+#    #+#             */
/*   Updated: 2025/07/22 03:16:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# define DEBUG 0

# define MAX_ERRNO 100
# define FT_ENOENT 2
# define FT_EIO 5
# define FT_EOVERFLOW 84
# define MSG_ENOENT "Invalid arg count."
# define MSG_EIO "Invalid input."
# define MSG_EOVERFLOW "Numerical overflow in arguments."

int	validate_args(int argc, char **argv);
int	ft_perror(int err_code);

#endif