/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:20:25 by sgadinga          #+#    #+#             */
/*   Updated: 2025/05/30 00:41:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	if (!n || !size)
		return (malloc(0));
	if (size != 0 && n > __SIZE_MAX__ / size)
		return (NULL);
	res = malloc(n * size);
	if (!res)
		return (NULL);
	ft_bzero(res, n * size);
	return (res);
}
