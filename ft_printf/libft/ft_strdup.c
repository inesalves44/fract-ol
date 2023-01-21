/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:23 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/08 16:47:48 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*test;
	int		len;

	len = ft_strlen(s);
	test = (char *)malloc(sizeof(char) * (len + 1));
	if (!test)
		return (NULL);
	ft_strlcpy(test, s, len + 1);
	return (test);
}
