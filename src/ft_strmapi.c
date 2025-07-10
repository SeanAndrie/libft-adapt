/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:45:17 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/06 22:51:43 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped;

	if (!s || !f)
		return (NULL);
	mapped = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!mapped)
		return (NULL);
	i = -1;
	while (s[++i])
		mapped[i] = f(i, s[i]);
	return (mapped);
}
