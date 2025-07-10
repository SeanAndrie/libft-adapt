/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:16:34 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/06 14:52:54 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*b_d;
	unsigned char	*b_s;

	b_d = (unsigned char *)dest;
	b_s = (unsigned char *)src;
	if (b_d < b_s || b_d >= b_s + n)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			*(b_d + n) = *(b_s + n);
	}
	return (dest);
}
