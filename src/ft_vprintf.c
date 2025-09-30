/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:29:38 by sgadinga          #+#    #+#             */
/*   Updated: 2025/09/07 23:37:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals/ft_printf/ft_printf.h"
#include <libft.h>

int	ft_vprintf(const char *format, va_list ap)
{
	int	len;

	len = ft_parse_format(STDOUT_FILENO, format, ap);
	return (len);
}
