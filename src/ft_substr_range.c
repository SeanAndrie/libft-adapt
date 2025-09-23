/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:12:27 by sgadinga          #+#    #+#             */
/*   Updated: 2025/09/23 18:30:00 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char    *ft_substr_range(const char *s, size_t start, size_t end)
{
    size_t  i;
    size_t  len;
    char    *sub;

    if (!s || end <= start || end > ft_strlen(s))
        return (NULL);
    len = end - start;
    sub = malloc(len + 1);
    if (!sub)
        return (NULL);
    i = 0;
    while (start < end && s[start])
        sub[i++] = s[start++];
    sub[i] = '\0';
    return (sub);
}
