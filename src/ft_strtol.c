/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:30:41 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/18 20:28:33 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals/ft_strtol/ft_strtol.h"
#include <libft.h>

static inline void	set_endptr(char **endptr, const char *pos)
{
	if (endptr)
		*endptr = (char *)pos;
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long	res;
	int		sign;
	int		digit;
	long	overflow;

	res = 0;
	if (!nptr || !*nptr)
		return (set_endptr(endptr, nptr), 0);
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
	}
	set_endptr(endptr, nptr);
	return (res * sign);
}
