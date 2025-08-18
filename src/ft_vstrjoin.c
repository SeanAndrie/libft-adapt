/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:49:51 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/18 22:54:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t get_total_len(unsigned int n, char *sep, va_list args)
{
    size_t  i;
    size_t  sep_len;
    size_t  total_len;

    i = 0;
    total_len = 0;
    sep_len = ft_strlen(sep);
    while (i < n)
    {
        total_len += ft_strlen(va_arg(args, char *));
        i++;
    }
    return (total_len + (sep_len * (n - 1)));
}

char    *ft_vstrjoin(unsigned int n, char *sep, ...)
{
    size_t  i;
    size_t  len;
    va_list args;
    char    *res;
    
    if (n == 0)
        return (NULL);
    va_start(args, sep);
    len = get_total_len(n, sep, args);
    va_end(args);
    res = ft_calloc(len + 1, sizeof(char *));
    if (!res)
        return (NULL);
    va_start(args, sep);
    i = 0;
    while (i < n)
    {
        ft_strlcat(res, va_arg(args, char *), len + 1);
        if (sep && i != n)
            ft_strlcat(res, sep, len + 1);
        i++;
    }
    va_end(args);
    return (res);
}
