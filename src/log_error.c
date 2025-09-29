/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:45:21 by sgadinga          #+#    #+#             */
/*   Updated: 2025/09/25 14:58:05 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	log_error(t_error_type type, const char *base, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
  if (base)
      ft_dprintf(STDERR_FILENO, "%s: ", base);
	if (type == ERROR_SYNTAX)
		ft_dprintf(STDERR_FILENO, "syntax error: ");
	else
		ft_dprintf(STDERR_FILENO, "runtime error: ");
	ft_vdprintf(STDERR_FILENO, format, args);
	va_end(args);
}
