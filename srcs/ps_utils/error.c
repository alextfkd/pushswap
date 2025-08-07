/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 02:52:59 by marvin            #+#    #+#             */
/*   Updated: 2025/07/22 16:44:52 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_ft_perror_debug(int err_code)
{
	int		i;
	char	*msgs[MAX_ERRNO];

	i = 0;
	if (err_code == 0)
	{
		ft_printf("(DEBUG MODE: No Error.)\n");
		return (0);
	}
	while (i < MAX_ERRNO)
		msgs[i++] = "";
	msgs[FT_ENOENT] = MSG_ENOENT;
	msgs[FT_EIO] = MSG_EIO;
	msgs[FT_EOVERFLOW] = MSG_EOVERFLOW;
	ft_printf("(ERROR CODE: %d) ", err_code);
	ft_printf("%s \n", msgs[err_code]);
	return (err_code);
}

static int	_ft_perror(int err_code)
{
	if (err_code == 0)
		return (0);
	ft_printf("Error\n");
	return (err_code);
}

int	ft_perror(int err_code)
{
	if (DEBUG == 1)
		return (_ft_perror_debug(err_code));
	return (_ft_perror(err_code));
}
