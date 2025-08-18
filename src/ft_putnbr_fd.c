/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:39:11 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/18 17:22:28 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
		return (ft_putstr_fd("2147483648", fd));
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10 > 0)
		len += ft_putnbr_fd(n / 10, fd);
	len += ft_putchar_fd(n % 10 + '0', fd);
	return (len);
}
