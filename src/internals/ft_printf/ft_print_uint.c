/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:55:06 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/15 18:57:49 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putuint_len(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n / 10 > 0)
		len += ft_putuint_len(n / 10, fd);
	len += ft_putchar_fd(n % 10 + '0', fd);
	return (len);
}

static int	ft_count_digits_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_parse_uint(t_formatspec *fs, unsigned int n)
{
	int	len;
	int	n_digits;
	int	total_len;

	len = 0;
	n_digits = ft_count_digits_unsigned(n);
	total_len = n_digits;
	if (fs->precision > n_digits)
		total_len += (fs->precision - n_digits);
	len += ft_right_justify(fs, &total_len);
	if (fs->precision > n_digits)
		len += ft_width_padding(fs->precision, n_digits, '0', fs->fd);
	if (!(n == 0 && fs->precision == 0))
		len += ft_putuint_len(n, fs->fd);
	else if (fs->precision == 0 && fs->width > 0)
		len += ft_putchar_fd(' ', fs->fd);
	len += ft_left_justify(fs, &len);
	return (len);
}
