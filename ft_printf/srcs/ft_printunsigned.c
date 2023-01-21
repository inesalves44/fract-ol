/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:03:16 by idias-al          #+#    #+#             */
/*   Updated: 2022/12/17 16:07:50 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulen(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_unsignedint(unsigned int n)
{
	int		len;
	int		count;
	char	*str;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = 0;
	len = ft_ulen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		str = NULL;
	str[len--] = '\0';
	while (n != 0)
	{
		str[len] = 48 + n % 10;
		n /= 10;
		len--;
	}
	count += ft_putstr(str);
	return (count);
}
