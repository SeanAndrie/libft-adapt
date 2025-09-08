/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:57:00 by sgadinga          #+#    #+#             */
/*   Updated: 2025/09/07 23:37:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals/ft_printf/ft_printf.h"
#include <libft.h>

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (0);
	va_start(args, format);
	len = ft_parse_format(STDOUT_FILENO, format, args);
	va_end(args);
	return (len);
}
