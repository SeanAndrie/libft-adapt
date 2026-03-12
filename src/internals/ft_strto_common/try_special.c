/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_special.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:12:08 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 13:13:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <internals/ft_strto_common.h>

static int  is_nan_or_inf(const char **nptr, double *special, int sign)
{
    if (ft_strncasecmp(*nptr, "infinity", 8) == 0)
        return (*nptr += 8, *special = sign * HUGE_VAL, 1);
    if (ft_strncasecmp(*nptr, "inf", 3) == 0)
        return (*nptr += 3, *special = sign * HUGE_VAL, 1);
    if (ft_strncasecmp(*nptr, "nan", 3) == 0)
    {
        *nptr += 3;
        if (**nptr == '(')
        {
            while (**nptr && **nptr != ')')
                (*nptr)++;
            if (**nptr == ')')
                (*nptr)++;
        }
        return (*special = NAN, 1);
    }
    return (0);
}

int  try_special(const char **nptr, char **endptr, int sign,
        double *special)
{
    if (!is_nan_or_inf(nptr, special, sign))
        return (0);
    set_endptr(endptr, *nptr);
    return (1);
}
