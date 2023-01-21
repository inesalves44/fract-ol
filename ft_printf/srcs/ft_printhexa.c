/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:27:25 by idias-al          #+#    #+#             */
/*   Updated: 2022/12/17 16:07:08 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n)
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

char	*ft_loop_hex(unsigned int n, int m)
{
	char	*base;
	char	*str;
	int		len;

	len = ft_hex(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	base = "0123456789abcdef";
	while (n != 0)
	{
		if (n % 16 > 9 && m == 2)
			str[len] = base[n % 16] - 32;
		else
			str[len] = base[n % 16];
		len--;
		n /= 16;
	}
	base = NULL;
	return (str);
}

int	ft_printhexa(unsigned int n, int m)
{
	char	*str;
	int		count;

	if (n == 0)
		count = ft_putchar('0');
	else
	{
		str = ft_loop_hex(n, m);
		count = ft_putstr(str);
	}
	return (count);
}
