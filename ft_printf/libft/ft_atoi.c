/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:06:43 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/08 17:42:03 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

int	is_signal(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	return_s(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	number;
	int	signal;

	i = 0;
	signal = 1;
	number = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (is_signal(nptr[i]) == 1)
	{
		signal = return_s(nptr[i]) * signal;
		i++;
	}
	while (nptr[i] != '\0' && is_number(nptr[i]) == 1)
	{
		number = 10 * number + (nptr[i] - '0');
		i++;
	}
	return (number * signal);
}
