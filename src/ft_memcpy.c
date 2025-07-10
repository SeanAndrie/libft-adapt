/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:07:58 by sgadinga          #+#    #+#             */
/*   Updated: 2025/05/30 16:10:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*b_d;
	unsigned char	*b_s;

	b_d = (unsigned char *)dest;
	b_s = (unsigned char *)src;
	while (n--)
		*b_d++ = *b_s++;
	return (dest);
}
