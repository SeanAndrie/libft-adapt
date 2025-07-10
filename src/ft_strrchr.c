/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:00:16 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/06 18:05:23 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	while (*s)
	{
		if (*s == (char)c)
			last = *s;
		s++;
	}
	if (*s == '\0')
		return ((char *)s);
	return (NULL);
}
