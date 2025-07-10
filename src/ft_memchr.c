/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:56:47 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/06 14:33:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b_s;

	b_s = (unsigned char *)s;
	while (n--)
	{
		if (*b_s == (unsigned char)c)
			return ((void *)b_s);
		b_s++;
	}
	return (NULL);
}
