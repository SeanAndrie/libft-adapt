/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:05:15 by sgadinga          #+#    #+#             */
/*   Updated: 2025/10/18 23:07:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t  ft_strcspn(const char *s1, const char *s2)
{
    size_t  len;

    len = 0;
    while (*s1)
    {
        if (ft_strchr(s2, *s1))
            break;
        len++;
        s1++;
    }
    return (len);
}

