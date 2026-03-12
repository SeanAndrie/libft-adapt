/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :::      ::::::::   */
/*                                                    +:+         +:++        */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  ++:++#++:++             */
/*                                                ++:++#++:++#+#++:++#++    */
/*   Created: 2026/03/12 03:03:57 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 03:03:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <internals/ft_strto_common.h>

float	ft_strtof(const char *nptr, char **endptr)
{
    float   res;
    double  value;

    value = ft_strtod(nptr, endptr);
    if (isinf(value) || fabs(value) > FLT_MAX)
    {
        errno = ERANGE;
        return (HUGE_VALF);
    }
    if (value != 0.0 && fabs(value) < FLT_MIN)
        errno = ERANGE;
    res = (float)value;
    return (res);
}
