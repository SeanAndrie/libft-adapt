/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:12:30 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/19 17:12:35 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

typedef struct s_node
{
	char			*buffer;
	size_t			length;
	struct s_node	*next;
}					t_node;

void				append_node(t_node **head, char *buffer);
void				update_remainder(t_node **head);
void				clear_list(t_node **head);

#endif
