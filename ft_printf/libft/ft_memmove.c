/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:13:26 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/07 11:19:48 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*new_dest;
	char	*new_src;

	if (!dest && !src)
		return (NULL);
	new_dest = (char *)dest;
	new_src = (char *)src;
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			new_dest[n - 1] = new_src[n - 1];
			n--;
		}
	}
	return (dest);
}
