/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:33:02 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:29:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals/ft_strto_common.h>
#include <libft.h>

int	convert_to_value(char c, int base)
{
	int	value;

	if (ft_isdigit(c))
		value = c - '0';
	else if (ft_isalpha(c))
		value = ft_tolower(c) - 'a' + 10;
	else
		return (-1);
	if (value >= base)
		return (-1);
	return (value);
}
