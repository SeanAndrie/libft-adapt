/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:41:11 by sgadinga          #+#    #+#             */
/*   Updated: 2025/06/06 23:05:12 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	count_words(const char *s, char c)
{
	int		in_word;
	size_t	n_words;

	in_word = 0;
	n_words = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			n_words++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (n_words);
}

static char	*alloc_word(const char **s, int c)
{
	size_t		len;
	char		*word;
	const char	*temp;

	while (**s && **s == c)
		(*s)++;
	len = 0;
	temp = *s;
	while (**s && **s != c)
	{
		s++;
		len++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, temp, len + 1);
	return (word);
}

static void	*free_tokens(char **tokens, size_t i)
{
	while (--i > 0)
		free(tokens[i]);
	free(tokens);
	return (NULL);
}

char	**ft_split(const char *s, int c)
{
	size_t	i;
	char	**tokens;

	tokens = ft_calloc(count_words(s, c) + 1, sizeof(char));
	if (!tokens)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && ft_isspace(*s))
			s++;
		else
		{
			tokens[i] = alloc_word(&s, c);
			if (!tokens[i])
				return (free_tokens(tokens, i));
			i++;
		}
	}
	return (tokens);
}
