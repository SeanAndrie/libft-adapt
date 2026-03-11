/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:15:54 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/13 17:27:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals/get_next_line.h>

void	clear_list(t_node **head)
{
	t_node	*next;

	while (*head)
	{
		next = (*head)->next;
		free((*head)->buffer);
		free(*head);
		*head = next;
	}
}

void	append_node(t_node **head, char *buffer)
{
	t_node	*node;
	t_node	*last;
	size_t	len;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->buffer = ft_strdup(buffer);
    len = ft_strlen(buffer);
	if (!node->buffer)
	{
		free(node);
		return ;
	}
	node->length = len;
	node->next = NULL;
	if (!*head)
	{
		*head = node;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = node;
}

void	update_remainder(t_node **head)
{
	t_node	*next;
	char	*remain;

	while ((*head)->next)
	{
		next = (*head)->next;
		free((*head)->buffer);
		free(*head);
		*head = next;
	}
	remain = ft_strchr((*head)->buffer, '\n');
	if (remain)
	{
		remain = ft_strdup(remain);
		clear_list(head);
		if (remain[0] != '\0')
			append_node(head, remain);
		free(remain);
	}
	else
		clear_list(head);
}
