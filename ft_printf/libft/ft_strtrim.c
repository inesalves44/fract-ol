/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:38:23 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/12 17:15:27 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	str = 0;
	if (s1 && set)
	{
		i = 0;
		len = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[len - 1] && ft_strchr(set, s1[len - 1]) && len > i)
			len--;
		str = (char *)malloc(sizeof(char) *(len - i + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s1 + i, len - i + 1);
	}
	return (str);
}
