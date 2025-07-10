/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:44:51 by sgadinga          #+#    #+#             */
/*   Updated: 2025/05/30 00:55:45 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	n_digits;

	n_digits = count_digits(n);
	res = ft_calloc(n_digits + 1, sizeof(char));
	if (!res)
		return (NULL);
	res[n_digits] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	n_digits--;
	while (n > 0)
	{
		res[n_digits--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
