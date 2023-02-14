/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:21:20 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/10 13:21:22 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	get_floatlen(double number)
{
	int		a;

	a = 0;
	if (number < 0)
		number *= (-1);
	while (number > 1)
	{
		number /= 10;
		a++;
	}
	a = a + 7;
	return (a);
}

int	ft_printfloat(double number)
{
	int		len;
	double	decimal;
	char	*str;
	int		i;

	len = get_floatlen(number) + 1;
	decimal = number - (int)number;
	i = len;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	str[--i] = '\0';
	i = i - 7;
	while (i)
	{
		printf("number int: %d\n", (int) number % 10);
		str[i] = (int)number % 10 + '0';
		printf("str: %c\n", str[i]);
		number /= 10;
		printf("number: %f\n", number);
		i--;
	}
	return(len);
}

int main()
{
	ft_printfloat(1000.2);
}
