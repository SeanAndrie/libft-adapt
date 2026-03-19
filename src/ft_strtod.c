/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:03:57 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 10:37:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <internals/ft_strto_common.h>

static double	return_with_endptr(char **endptr, const char *nptr,
		double value)
{
	set_endptr(endptr, nptr);
	return (value);
}

static double	apply_exponent(double res, int exp, int sign)
{
	res = res * pow(10.0, exp);
	if (isinf(res))
	{
		errno = ERANGE;
		return (sign * HUGE_VAL);
	}
	if (res == 0.0)
		errno = ERANGE;
	return (sign * res);
}

static int	parse_nptr(const char **nptr, double *res, int sign)
{
	int	exp;
	int	has_digits;

	has_digits = 0;
	exp = 0;
	if (parse_digits(nptr, res, &has_digits))
		return (1);
	if (parse_fraction(nptr, res, &has_digits))
		return (1);
	if (!has_digits)
		return (-1);
	if (parse_exponent(nptr, &exp))
		return (1);
	if (exp != 0)
		*res = apply_exponent(*res, exp, sign);
	else
		*res = sign * *res;
	return (0);
}

double	ft_strtod(const char *nptr, char **endptr)
{
	double	res;
	int		sign;
	double	special;
	int		ret;

	if (!nptr || !*nptr)
		return (return_with_endptr(endptr, nptr, 0.0));
	res = 0.0;
	skip_whitespace_and_sign(&nptr, &sign);
	if (try_special(&nptr, endptr, sign, &special))
		return (special);
	ret = parse_nptr(&nptr, &res, sign);
	if (ret == 1)
		return (return_with_endptr(endptr, nptr, sign * HUGE_VAL));
	if (ret == -1)
		return (return_with_endptr(endptr, nptr, 0.0));
	return (return_with_endptr(endptr, nptr, res));
}
