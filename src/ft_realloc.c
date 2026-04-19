/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:27:55 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 20:40:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>

void    *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void    *res;
    size_t  copy_size;

    if (!ptr)
        return (malloc(new_size));
    if (old_size == 0)
    {
        errno = EINVAL;
        return (NULL);
    }
    if (new_size == 0)
        return (free(ptr), NULL);
    res = malloc(new_size);
    if (!res)
        return (NULL);
    if (old_size < new_size)
        copy_size = old_size;
    else
        copy_size = new_size;
    ft_memcpy(res, ptr, copy_size);
    free(ptr);
    return (res);
}
