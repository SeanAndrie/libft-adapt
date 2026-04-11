/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace_and_sign.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:28:02 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 10:39:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals/ft_strto_common.h>
#include <libft.h>

void	skip_whitespace_and_sign(const char **nptr, int *sign)
{
	*sign = 1;
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			*sign = -1;
		(*nptr)++;
	}
}
