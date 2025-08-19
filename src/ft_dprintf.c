/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:30:55 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/18 21:38:50 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals/ft_printf/ft_printf.h"
#include <libft.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	int		len;
	va_list	args;

	if (fd < 0)
		return (-1);
	len = 0;
	va_start(args, format);
	len = ft_parse_format(format, fd, args);
	va_end(args);
	return (len);
}
