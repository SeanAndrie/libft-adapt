/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:02:31 by sgadinga          #+#    #+#             */
/*   Updated: 2025/05/30 16:07:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b_s1;
	unsigned char	*b_s2;

	b_s1 = (unsigned char *)s1;
	b_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*b_s1 != *b_s2)
			return (*b_s1 - *b_s2);
		b_s1++;
		b_s2++;
	}
	return (0);
}
