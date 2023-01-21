/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:59:06 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/09 10:33:36 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	z;
	size_t	i;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		z = 0;
		while (little[z] == big[i + z] && (i + z) < len)
		{
			if (little[z + 1] == '\0')
				return ((char *)&big[i]);
			z++;
		}
		i++;
	}
	return (NULL);
}
