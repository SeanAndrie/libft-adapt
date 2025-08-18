/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:52:51 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/18 19:02:37 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_str(t_formatspec *fs, char *s)
{
	int	len;
	int	str_len;
	int	n_char;

	if (!s)
	{
		if (fs->precision < 5 && fs->precision > -1)
			s = "\0";
		else
			s = "(null)";
	}
	str_len = (int)ft_strlen(s);
	if (fs->precision >= 0 && fs->precision < str_len)
		n_char = fs->precision;
	else
		n_char = str_len;
	len = 0;
	if (fs->width > n_char && !ft_strchr(fs->flags, '-'))
		len += ft_width_padding(fs->width, n_char, ' ', fs->fd);
	len += write(fs->fd, s, n_char);
	if (fs->width > n_char && ft_strchr(fs->flags, '-'))
		len += ft_width_padding(fs->width, n_char, ' ', fs->fd);
	return (len);
}
