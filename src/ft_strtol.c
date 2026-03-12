/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:30:41 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 13:49:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errno.h>
#include <internals/ft_strto_common.h>

int	handle_base_prefix(const char **nptr, int base)
{
	if (base == 0)
	{
		if (**nptr == '0')
		{
			(*nptr)++;
			if (ft_tolower(**nptr) == 'x')
			{
				base = 16;
				(*nptr)++;
			}
			else
				base = 8;
		}
		else
			base = 10;
	}
	else if (base == 16 && **nptr == '0' && *(*nptr + 1) != '\0'
		&& ft_tolower(*(*nptr + 1)) == 'x')
		(*nptr) += 2;
	return (base);
}

static long	check_overflow(long res, int digit, int base, int sign)
{
    if (sign == 1 && res > (LONG_MAX - digit) / base)
    {
        errno = ERANGE;
        return (LONG_MAX);
    }
    if (sign == -1 && res > -(LONG_MIN + digit) / base)
    {
        errno = ERANGE;
        return (LONG_MIN);
    }
    return (0);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long	res;
	int		sign;
	int		digit;
	long	overflow;

	if (!nptr || !*nptr)
		return (set_endptr(endptr, nptr), 0);
	res = 0;
	skip_whitespace_and_sign(&nptr, &sign);
	if (base != 0 && (base < 2 || base > 36))
		return (set_endptr(endptr, nptr), errno = EINVAL, 0);
	base = handle_base_prefix(&nptr, base);
	while (1)
	{
		digit = convert_to_value(*nptr, base);
		if (digit == -1)
			break ;
		overflow = check_overflow(res, digit, base, sign);
		if (overflow)
			return (set_endptr(endptr, nptr), errno = ERANGE, overflow);
		res = res * base + digit;
		nptr++;
        set_endptr(endptr, nptr);
	}
	return (res * sign);
}
