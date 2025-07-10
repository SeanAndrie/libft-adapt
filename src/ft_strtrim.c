/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:23:56 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/06 23:36:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int in_set(const char *set, int c)
{
	while (*set)
	{
		if (*set == (char)c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char		*trimmed;
	const char 	*start;
	const char 	*end;
	size_t		len;

	if (!s)
		return (NULL);
	if (!set)
		return (ft_strdup(s));
	start = s;
	while (*start && in_set(set, *start))
		start++;
	end = s + ft_strlen(s) - 1;
	while (end > start && in_set(set, *end))
		end--;
	len = end - start + 1;
	if (len == 0)
		return (ft_strdup(""));
	trimmed = malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, start, len + 1);
	return (trimmed);
}
