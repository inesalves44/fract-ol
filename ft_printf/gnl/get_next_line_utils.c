/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:04:04 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/19 19:36:18 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	mod_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*mod_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((mod_strlen(s1) + mod_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[mod_strlen(s1) + mod_strlen(s2)] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*mod_strdup(char *s)
{
	char	*test;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = mod_strlen(s);
	test = (char *)malloc(sizeof(char) * (len + 1));
	if (!test)
		return (NULL);
	i = 0;
	while (i < len)
	{
		test[i] = s[i];
		i++;
	}
	test[len] = '\0';
	return (test);
}

char	*mod_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[mod_strlen(s)]);
	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&s[i]);
}
