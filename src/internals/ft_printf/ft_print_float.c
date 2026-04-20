/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:45:21 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/14 14:08:12 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <math.h>

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

static int	ft_float_total_len(t_formatspec *fs, double n, int precision)
{
	int	total;
	int	int_part;

	int_part = (int)n;
	if (n < 0 && int_part == 0)
		int_part = -1;
	total = ft_count_digits_signed(int_part);
	total += 1 + precision;
	if (n < 0 || ft_strchr(fs->flags, '+') || ft_strchr(fs->flags, ' '))
		total++;
	return (total);
}

static int	ft_print_int_part(t_formatspec *fs, double n)
{
	t_formatspec	int_fs;

	int_fs.fd = fs->fd;
	int_fs.flags[0] = '\0';
	int_fs.width = 0;
	int_fs.precision = -1;
	int_fs.specifier = 'd';
	if (n == (double)INT_MIN)
		return (ft_parse_dec_int(&int_fs, INT_MIN));
	if (n < 0)
		return (ft_putchar_fd('-', fs->fd) + ft_parse_dec_int(&int_fs,
				(int)-n));
	if (ft_strchr(fs->flags, '+'))
		return (ft_putchar_fd('+', fs->fd) + ft_parse_dec_int(&int_fs, (int)n));
	if (ft_strchr(fs->flags, ' '))
		return (ft_putchar_fd(' ', fs->fd) + ft_parse_dec_int(&int_fs, (int)n));
	return (ft_parse_dec_int(&int_fs, (int)n));
}

static int	ft_pad_and_justify(t_formatspec *fs, double n, int frac_part,
		int precision)
{
	int	len;
	int	total_len;

	total_len = ft_float_total_len(fs, n, precision);
	len = 0;
	if (ft_strchr(fs->flags, '0') && !ft_strchr(fs->flags, '-'))
	{
		len += ft_print_int_part(fs, n);
		len += ft_width_padding(fs->width, total_len, '0', fs->fd);
	}
	else
	{
		len += ft_right_justify(fs, &total_len);
		len += ft_print_int_part(fs, n);
	}
	if (precision > 0)
		len += ft_putchar_fd('.', fs->fd)
			+ ft_parse_dec_int(&(t_formatspec){fs->fd, "\0", 0, precision, 'd'},
				frac_part);
	len += ft_left_justify(fs, &total_len);
	return (len);
}

int	ft_parse_float(t_formatspec *fs, double n)
{
	int		int_part;
	int		frac_part;
	double	frac;

	if (isnan(n))
		return (ft_putstr_fd("nan", fs->fd));
	if (isinf(n) && n < 0)
		return (ft_putstr_fd("-inf", fs->fd));
	if (isinf(n))
		return (ft_putstr_fd("inf", fs->fd));
	int_part = (int)n;
	frac = fabs(n - (double)int_part);
	frac_part = (int)round(frac * pow(10, fs->precision));
	if (frac_part >= (int)pow(10, fs->precision))
	{
		frac_part = 0;
		if (n < 0)
			int_part--;
		else
			int_part++;
	}
	return (ft_pad_and_justify(fs, n, frac_part, fs->precision));
}
