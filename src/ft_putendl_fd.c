/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:36:36 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/18 17:22:35 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putendl_fd(char *s, int fd)
{
	int	s_len;
	int	nl_len;

	s_len = ft_putstr_fd(s, fd);
	if (s_len == -1)
		return (-1);
	nl_len = ft_putchar_fd('\n', fd);
	if (nl_len == -1)
		return (-1);
	return (s_len + nl_len);
}
