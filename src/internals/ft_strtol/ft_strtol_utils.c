/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:02:22 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/13 16:25:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtol.h"

void skip_whitespace_and_sign(const char **nptr, int *sign)
{
    while (**nptr && ft_isspace(**nptr))
        (*nptr)++;
    if (**nptr == '-' || **nptr == '+')
    {
        if (**nptr == '-')
            *sign = -1;
        (*nptr)++;
    }
}

int handle_base_prefix(const char **nptr, int base)
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
    else if (base == 16 && **nptr == '0' && *(*nptr + 1) && ft_tolower(*(*nptr + 1)) == 'x')
        (*nptr) += 2;
    return (base);
}

int convert_to_value(char c, int base)
{
    int value;

    if (ft_isdigit(c))
        value = c - '0';
    else if (ft_isalpha(c))
        value = ft_tolower(c) + 'a' + 10;
    else
        return (-1);
    if (value >= base)
        return (-1);
    return (value);
}

long    check_overflow(long res, int digit, int base, int sign)
{
    if (res > ((LONG_MAX - digit) / base))
    {
        if (sign == 1)
            return (LONG_MAX);
        else
            return (LONG_MIN);
    }
    return (0);
}
