/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exponent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:42:12 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 13:00:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <internals/ft_strto_common.h>

int parse_exponent(const char **nptr, int *exp)
{
    int digit;
    int exp_sign;

    *exp = 0;
    if (**nptr != 'e' && **nptr != 'E')
        return (0);
    (*nptr)++;
    exp_sign = 1;
    if (**nptr == '-' || **nptr == '+')
    {
        if (**nptr == '-')
            exp_sign = -1;
        (*nptr)++;
    }
    while (1)
    {
        digit = convert_to_value(**nptr, 10);
        if (digit == -1)
            break;
        if (*exp > (INT_MAX - digit) / 10)
            return (1);
        *exp = *exp * 10 + digit;
        (*nptr)++;
    }
    return (*exp *= exp_sign, 0);
}
