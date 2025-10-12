/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:00:18 by sgadinga          #+#    #+#             */
/*   Updated: 2025/05/30 00:15:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	check_overflow(long res, char digit, int sign)
{
	if (res >= (INT_MAX / 10) || ((res >= (INT_MAX / 10)) && (digit - '0') > 7))
	{
		if (sign == 1)
			return (INT_MAX);
		else
			return (INT_MIN);
	}
	return (-1);
}

int	ft_atoi(const char *s)
{
	long	res;
	int		sign;
	int		overflow;

	res = 0;
	sign = 1;
	overflow = -1;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && ft_isdigit(*s))
	{
		overflow = check_overflow(res, *s, sign);
		if (overflow != -1)
			return (overflow);
		res = res * 10 + *s++ - '0';
	}
	return ((int)res * sign);
}
