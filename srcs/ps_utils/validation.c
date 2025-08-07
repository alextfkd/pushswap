/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 02:47:26 by marvin            #+#    #+#             */
/*   Updated: 2025/07/24 18:46:47 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_alphasign(const char *str)
{
	const char	*p;

	if (str == NULL)
		return (0);
	p = str;
	if (ft_isdigit(*p) == 1 || *p == '-' || *p == '+')
		p++;
	while (*p != '\0')
	{
		if (ft_isdigit(*p) == 0)
			return (0);
		p++;
	}
	return (1);
}

static int	ft_check_overflow(const char *nptr)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) != 0)
	{
		if (sign == 1 && res > INT_MAX / 10)
			return (1);
		if (sign == -1 && res - 10 > INT_MAX / 10)
			return (1);
		if (sign == 1 && 10 * res > INT_MAX - (*nptr - '0'))
			return (1);
		if (sign == -1 && 10 * res - 1 > INT_MAX - (*nptr - '0'))
			return (1);
		res = 10 * res + (*nptr++ - '0');
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int	status;
	int	i;

	status = 0;
	i = 1;
	if (argc <= 1)
		status = FT_ENOENT;
	while (i < argc)
	{
		if (ft_is_alphasign(argv[i]) == 0)
		{
			status = FT_EIO;
			break ;
		}
		if (ft_check_overflow(argv[i++]) == 1)
		{
			status = FT_EOVERFLOW;
			break ;
		}
	}
	return (status);
}
