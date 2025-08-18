/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:51:27 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/15 18:29:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_char(t_formatspec *fs, int c)
{
	int	len;

	len = 0;
	if (fs->width > 1 && !ft_strchr(fs->flags, '-'))
		len += ft_width_padding(fs->width, 1, ' ', fs->fd);
	len += ft_putchar_fd(c, fs->fd);
	len += ft_left_justify(fs, &len);
	return (len);
}
