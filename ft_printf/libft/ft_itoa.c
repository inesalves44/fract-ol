/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:31:09 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/12 16:58:34 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long int n)
{
	int	a;

	a = 0;
	if (n <= 0)
	{
		n = n * (-1);
		a++;
	}
	while (n)
	{
		a++;
		n = n / 10;
	}
	return (a);
}

char	*ft_string(char *str, long int n, int i)
{
	while (n != 0)
	{
		str[i] = 48 + n % 10;
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	number;
	int			i;

	number = n;
	i = ft_len(number);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (number == 0)
		str[0] = '0';
	else if (number < 0)
	{
		str[0] = '-';
		number = number * (-1);
	}
	str = ft_string(str, number, i);
	return (str);
}
