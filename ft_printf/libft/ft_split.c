/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:41:35 by idias-al          #+#    #+#             */
/*   Updated: 2022/12/31 11:06:09 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *str, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			a++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (a);
}

void	ft_free(char **split, char *new)
{
	int	i;

	i = 0;
	while (split[i] != new)
	{
		free(split[i]);
		i++;
		if (split[i] == new)
			free(split[i]);
	}
	free(split);
}

char	*create_words(char const *str, int final, int inicial, char **split)
{
	int		n;
	int		len;
	char	*word;

	word = (char *)malloc(sizeof(char) * (final - inicial + 1));
	if (!word)
	{
		ft_free(split, word);
		return (NULL);
	}
	n = 0;
	len = final - inicial;
	while (n < len)
	{
		word[n] = str[inicial + n];
		n++;
	}
	word[n] = '\0';
	return (word);
}

char	**create_strings(char **new, int len_str, char c, char const *s)
{
	int	i;
	int	a;
	int	y;
	int	len;

	len = ft_strlen(s);
	i = 0;
	y = 0;
	a = 0;
	while (y <= (len_str - 1))
	{
		if (s[i] != c)
		{
			a = i;
			while (s[i] != c && i < len)
				i++;
			new[y++] = create_words(s, i, a, new);
		}
		i++;
	}
	new[y] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		len_str;

	len_str = count_words(s, c);
	new = (char **)malloc((len_str + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	new = create_strings(new, len_str, c, s);
	return (new);
}
