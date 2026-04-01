/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strto_common.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:31:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 12:45:12 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTO_COMMON_H
# define FT_STRTO_COMMON_H

# include <errno.h>
# include <math.h>

# define FLT_MAX 3.402823466e+38F
# define FLT_MIN 1.17549435E-38F

void	set_endptr(char **endptr, const char *pos);
void	skip_whitespace_and_sign(const char **nptr, int *sign);

int		convert_to_value(char c, int base);
int		parse_exponent(const char **nptr, int *exp);
int		parse_digits(const char **nptr, double *res, int *has_digits);
int		parse_fraction(const char **nptr, double *res, int *has_digits);
int		try_special(const char **nptr, char **endptr, int sign,
			double *special);

#endif
