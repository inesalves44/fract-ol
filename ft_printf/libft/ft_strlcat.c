/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:21:22 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/12 17:44:28 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	if (!dst && !src)
		return (0);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
		return (size + len_src);
	while (src[i] && (len_dst + 1) < size)
		dst[len_dst++] = src[i++];
	dst[len_dst] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
