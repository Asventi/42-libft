/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:36:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/07/22 14:36:28 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

int	ft_atoi_ptr(char **nptr)
{
	int						sign;
	long long int			res;

	sign = 1;
	res = 0;
	while (ft_isspace(**nptr))
		*nptr += 1;
	if (**nptr == '-' || **nptr == '+')
	{
		sign *= -1 * (**nptr - 44);
		*nptr += 1;
	}
	while ('0' <= **nptr && **nptr <= '9')
	{
		if ((res * 10 + **nptr - '0') / 10 != res)
			return (-1 * (sign > 0));
		res = res * 10 + **nptr - '0';
		*nptr += 1;
	}
	*nptr += 1;
	return ((int)(sign * res));
}

float	ft_atof(char *str)
{
	float	res;
	float	frac_res;

	res = (float)ft_atoi_ptr(&str);
	frac_res = (float)ft_atoi(str);
	while (frac_res >= 1)
		frac_res /= 10;
	while (*str == '0')
	{
		frac_res /= 10;
		str++;
	}
	res += frac_res;
	return (res);
}
