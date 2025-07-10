/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:58:36 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/06 23:59:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list  *ft_lstlast(t_list *lst)
{
    t_list *last;

    last = lst;
    while (last->next)
        last = last->next;
    return (last);
}
