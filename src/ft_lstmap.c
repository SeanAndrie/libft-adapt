/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:17:13 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/07 00:26:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *node;
    t_list *mapped;

    mapped = NULL;
    while (lst)
    {
        node = ft_lstnew(f(lst->content));
        if (!node)
        {
            ft_lstclear(&mapped, del);
            return (NULL);
        }
        ft_lstadd_back(&mapped, node);
        lst = lst->next;
    }
    return (mapped);
}