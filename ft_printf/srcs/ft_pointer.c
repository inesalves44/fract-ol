/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:21:27 by idias-al          #+#    #+#             */
/*   Updated: 2022/12/17 16:06:27 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_longhex(unsigned long long int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

int	ft_printhexapointer(unsigned long long int n)
{
	int		len;
	char	*str;
	char	*base;
	int		count;

	len = ft_longhex(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		str = NULL;
	str[len--] = '\0';
	base = "0123456789abcdef";
	while (n != 0)
	{
		str[len--] = base[n % 16];
		n /= 16;
	}
	count = ft_putstr(str);
	base = NULL;
	return (count);
}

int	ft_printpointer(unsigned long long int addr)
{
	int	count;

	count = 0;
	if (!addr)
		count += write_string("(nil)");
	else
	{
		count += write_string("0x");
		count += ft_printhexapointer(addr);
	}
	return (count);
}
