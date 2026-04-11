/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:33:48 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:29:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals/ft_strto_common.h>

int	parse_digits(const char **nptr, double *res, int *has_digits)
{
	int	digit;

	*res = 0.0;
	while (1)
	{
		digit = convert_to_value(**nptr, 10);
		if (digit == -1)
			break ;
		if (*res > (DBL_MAX - digit) / 10.0)
			return (1);
		*res = *res * 10.0 + digit;
		*has_digits = 1;
		(*nptr)++;
	}
	return (0);
}
