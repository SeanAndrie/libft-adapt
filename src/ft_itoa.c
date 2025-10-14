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
    long    num;
	char	*res;
	size_t	n_digits;

    num = (long)n;
	n_digits = count_digits(num);
	res = ft_calloc(n_digits + 1, sizeof(char));
	if (!res)
		return (NULL);
	res[n_digits] = '\0';
    if (num == 0)
        return (res[0] = '0', res);
    if (num < 0)
    {
        res[0] = '-';
        num = -num;
    }
	n_digits--;
	while (num > 0)
	{
		res[n_digits--] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
