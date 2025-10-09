/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:11:17 by sgadinga          #+#    #+#             */
/*   Updated: 2025/10/07 21:26:43 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	calculate_size(const char *s, const char *set)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (!ft_strchr(set, *s))
			size++;
		s++;
	}
	return (size);
}

static size_t	placeholders_size(const char *s, const char *set)
{
	size_t	size;
	int		in_set;
	int		prev_state;

	size = 0;
	in_set = 0;
	prev_state = 0;
	while (*s)
	{
		in_set = (ft_strchr(set, *s) != NULL);
		if (prev_state != in_set)
			size++;
		prev_state = in_set;
		s++;
	}
	return (size);
}

static char	*alloc_placeholder(const char **s, const char *set)
{
	char		*ph;
	size_t		len;
	const char	*start;

	len = 0;
	start = *s;
	if (!s || !*s || !**s)
		return (NULL);
	if (!ft_strchr(set, **s))
	{
		while (**s && !ft_strchr(set, **s))
			(*s)++;
		return (ft_strdup(""));
	}
	while (**s && ft_strchr(set, **s))
	{
		(*s)++;
		len++;
	}
	ph = ft_calloc(len + 1, sizeof(char));
	if (!ph)
		return (NULL);
	ft_strlcpy(ph, start, len + 1);
	return (ph);
}

static char	**create_placeholders(const char *s, const char *set)
{
	int		i;
	char	**phs;

	if (!s || !set)
		return (NULL);
	phs = ft_calloc(placeholders_size(s, set) + 1, sizeof(char *));
	if (!phs)
		return (NULL);
	i = 0;
	while (*s)
	{
		phs[i] = alloc_placeholder(&s, set);
		if (!phs[i])
		{
			while (--i >= 0)
				free(phs[i]);
			free(phs);
			return (NULL);
		}
		i++;
	}
	return (phs);
}

char	*ft_strstrip(const char *s, const char *set, char ***placeholders)
{
	size_t	size;
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (!set)
		return (ft_strdup(s));
	if (placeholders)
		*placeholders = create_placeholders(s, set);
	size = calculate_size(s, set);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (!ft_strchr(set, *s))
			res[i++] = *s;
		s++;
	}
	res[i] = '\0';
	return (res);
}
