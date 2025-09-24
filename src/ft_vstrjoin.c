/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 21:49:51 by sgadinga          #+#    #+#             */
/*   Updated: 2025/09/25 00:01:50 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	get_total_len(unsigned int n, char *sep, va_list args)
{
	size_t	i;
	size_t	sep_len;
	size_t	total_len;
	char	*str;

	i = 0;
	sep_len = 1;
	total_len = 0;
	if (sep)
		sep_len = ft_strlen(sep);
	while (i < n)
	{
		str = va_arg(args, char *);
		if (str)
			total_len += ft_strlen(str);
		i++;
	}
	return (total_len + (sep_len * (n - 1)));
}

char	*ft_vstrjoin(unsigned int n, char *sep, ...)
{
	size_t	len;
	va_list	args;
	char	*str;
	char	*res;

	if (n == 0)
		return (ft_strdup(""));
	va_start(args, sep);
	len = get_total_len(n, sep, args);
	va_end(args);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	va_start(args, sep);
	while (n-- > 0)
	{
		str = va_arg(args, char *);
		if (str)
			ft_strlcat(res, str, len + 1);
		if (sep && n > 0)
			ft_strlcat(res, sep, len + 1);
	}
	va_end(args);
	return (res);
}
