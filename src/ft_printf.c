/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:57:00 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/15 19:45:28 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "internals/ft_printf/ft_printf.h"

static int	ft_parse_by_spec(t_formatspec *fs, va_list args)
{
	int	len;

	len = 0;
	if (fs->specifier == 'c')
		len = ft_parse_char(fs, va_arg(args, int));
	else if (fs->specifier == 's')
		len = ft_parse_str(fs, va_arg(args, char *));
	else if (fs->specifier == 'd' || fs->specifier == 'i')
		len = ft_parse_dec_int(fs, va_arg(args, int));
	else if (fs->specifier == 'p')
		len = ft_parse_hex(fs, va_arg(args, void *));
	else if (fs->specifier == 'u')
		len = ft_parse_uint(fs, va_arg(args, unsigned int));
	else if (fs->specifier == 'x' || fs->specifier == 'X')
		len = ft_parse_hex(fs, va_arg(args, void *));
	else
		len = ft_putchar_fd(fs->specifier, fs->fd);
	return (len);
}

static int	ft_parse_format(const char *format, va_list args)
{
	int				len;
	t_formatspec	*fs;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			fs = ft_create_fs(&format);
			if (!fs)
			{
				len += ft_putchar_fd('%', fs->fd);
				continue ;
			}
			len += ft_parse_by_spec(fs, args);
			free(fs);
		}
		else
			len += ft_putchar_fd(*format, fs->fd);
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (0);
	len = 0;
	va_start(args, format);
	len = ft_parse_format(format, args);
	va_end(args);
	return (len);
}
