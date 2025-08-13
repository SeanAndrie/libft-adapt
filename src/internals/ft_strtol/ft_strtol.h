/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:08:44 by sgadinga          #+#    #+#             */
/*   Updated: 2025/08/13 16:28:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOL_H
# define FT_STRTOL_H

# include <libft.h>
# include <errno.h>

void    skip_whitespace_and_sign(const char **nptr, int *sign);
int     handle_base_prefix(const char **nptr, int base);
int     convert_to_value(char c, int base);
long    check_overflow(long res, int digit, int base, int sign);

#endif
