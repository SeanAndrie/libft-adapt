/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:39:15 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/15 23:40:07 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*

- skip whitespaces
- can have '-' or '+'

bases:
	- if base is 0 or 16
		- str can include "0x" or "0X" prefix
		- read in base 16
	- if base is 0 or 2
		- str can include "0b" or "0B" prefix
		- read in base 2
	- if base 0
		- read in base 2,
		- unless following char in str is '0', read in base 8

*/

static int get_base(const char **nptr, int base)
{
    
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long	res;
	int		sign;

    (void)endptr;
	res = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
    base = get_base(&nptr, base);
    printf("Base: %d\n", base);
    while (1)
    {
        
    }
    return (res * sign);
}
