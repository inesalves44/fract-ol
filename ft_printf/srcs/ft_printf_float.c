/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:21:20 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/10 20:56:35 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_printfloat(double number)
{
	int		count;
	double	decimal;

	count = ft_putnbr((int)number);
	count += write(1, ".", 1);
	if (number < 0)
		number *= -1;
	decimal = (number - (int)number) * 1000000;
	count += ft_putnbr((int)decimal);
	return (count);
}
