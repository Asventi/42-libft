/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:59:17 by pjarnac           #+#    #+#             */
/*   Updated: 2024/11/12 15:34:48 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int						sign;
	unsigned long long int	res;
	int						i;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign *= -1 * (nptr[i] - 44);
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		if (res > -(unsigned long long int)LLONG_MIN && sign == -1)
			return (0);
		else if (res > LLONG_MAX && sign == 1)
			return (-1);
		i++;
	}
	return ((int)(sign * res));
}
