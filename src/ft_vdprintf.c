/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:36:13 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 02:25:18 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <internals/ft_printf.h>

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	len;

	if (fd < 0)
		return (-1);
	len = ft_parse_format(fd, format, ap);
	return (len);
}
