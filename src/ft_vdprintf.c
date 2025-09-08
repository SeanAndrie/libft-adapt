/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:36:13 by sgadinga          #+#    #+#             */
/*   Updated: 2025/09/07 23:38:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals/ft_printf/ft_printf.h"
#include <libft.h>

int ft_vdprintf(int fd, const char *format, va_list ap)
{
    int len;

	if (fd < 0)
		return (-1);
    len = ft_parse_format(fd, format, ap);
    return (len);
}
