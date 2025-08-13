/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:51:27 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/13 17:04:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_parse_char(t_formatspec *fs, int c)
{
	int	len;

	len = 0;
	if (fs->width > 1 && !ft_strchr(fs->flags, '-'))
		len += ft_width_padding(fs->width, 1, ' ');
	len += ft_putchar_len(c);
	len += ft_left_justify(fs, &len);
	return (len);
}
