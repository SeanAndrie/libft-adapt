/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:54:11 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/18 19:47:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits_signed(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	ft_putdi_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n < 0)
		n = -n;
	if (n / 10 > 0)
		len += ft_putdi_fd(n / 10, fd);
	len += ft_putchar_fd(n % 10 + '0', fd);
	return (len);
}

static int	ft_apply_sign(t_formatspec *fs, int n)
{
	if (n < 0)
		return (ft_putchar_fd('-', fs->fd));
	else if (ft_strchr(fs->flags, '+'))
		return (ft_putchar_fd('+', fs->fd));
	else if (ft_strchr(fs->flags, ' '))
		return (ft_putchar_fd(' ', fs->fd));
	return (0);
}

static int	ft_pad_and_justify(t_formatspec *fs, int n, int n_digits,
		int total_len)
{
	int	len;

	len = 0;
	len = 0;
	if (ft_strchr(fs->flags, '0') && fs->precision < 0 && !ft_strchr(fs->flags,
			'-'))
	{
		len += ft_apply_sign(fs, n);
		len += ft_width_padding(fs->width, total_len, '0', fs->fd);
	}
	else
	{
		len += ft_right_justify(fs, &total_len);
		len += ft_apply_sign(fs, n);
	}
	if (fs->precision > n_digits)
		len += ft_width_padding(fs->precision, n_digits, '0', fs->fd);
	if (!(n == 0 && fs->precision == 0))
		len += ft_putdi_fd(n, fs->fd);
	else if (fs->precision == 0 && fs->width > 0)
		len += ft_putchar_fd(' ', fs->fd);
	len += ft_left_justify(fs, &total_len);
	return (len);
}

int	ft_parse_dec_int(t_formatspec *fs, int n)
{
	int	len;
	int	n_digits;
	int	total_len;

	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fs->fd));
	len = 0;
	n_digits = ft_count_digits_signed(n);
	total_len = n_digits;
	if (fs->precision > n_digits)
		total_len += (fs->precision - n_digits);
	if (n < 0 || ft_strchr(fs->flags, '+'))
		total_len++;
	len += ft_pad_and_justify(fs, n, n_digits, total_len);
	return (len);
}
