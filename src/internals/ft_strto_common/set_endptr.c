/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_endptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:35:22 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 03:47:15 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <internals/ft_strto_common.h>

void	set_endptr(char **endptr, const char *pos)
{
	if (endptr)
		*endptr = (char *)pos;
}
