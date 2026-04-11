/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_endptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:35:22 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 10:39:06 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals/ft_strto_common.h>
#include <libft.h>

void	set_endptr(char **endptr, const char *pos)
{
	if (endptr)
		*endptr = (char *)pos;
}
