/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:34:38 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 13:00:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals/ft_strto_common.h>

int	parse_fraction(const char **nptr, double *res, int *has_digits)
{
	int		digit;
	double	scale;

	if (**nptr != '.')
		return (0);
	(*nptr)++;
	scale = 0.1;
	while (1)
	{
		digit = convert_to_value(**nptr, 10);
		if (digit == -1)
			break ;
		*res += digit * scale;
		scale *= 0.1;
		*has_digits = 1;
		(*nptr)++;
	}
	return (0);
}
