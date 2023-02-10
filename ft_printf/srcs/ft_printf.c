/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:33:32 by idias-al          #+#    #+#             */
/*   Updated: 2022/12/17 16:06:47 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_args(va_list args, char c)
{
	size_t	print;

	print = 0;
	if (c == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		print += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		print += ft_unsignedint(va_arg(args, unsigned long int));
	else if (c == 's')
		print += write_string(va_arg(args, char *));
	else if (c == 'p')
		print += ft_printpointer(va_arg(args, unsigned long long int));
	else if (c == 'x')
		print += ft_printhexa(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		print += ft_printhexa(va_arg(args, unsigned int), 2);
	else if (c == 'f')
		print += ft_printfloat(va_arg(args, double));
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		j;
	int		print;

	va_start(ptr, str);
	j = 0;
	print = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '%')
		{
			if (str[j + 1] != '%')
				print += ft_args(ptr, str[j + 1]);
			else
				print += ft_putchar('%');
			j++;
		}
		else
			print += ft_putchar(str[j]);
		j++;
	}
	return (print);
}
