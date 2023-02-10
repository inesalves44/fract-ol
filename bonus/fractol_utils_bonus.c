/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:06:28 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 20:29:26 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

double	ft_atod(char *str)
{
	double	number;
	int		signal;
	int		i;
	double	n;

	signal = 1;
	number = 0;
	n = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signal = -1;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0' )
		number = number * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		number = number + (str[i++] - '0') * 0.1 * n;
		n /= 10;
	}
	return ((number) * signal);
}

void	print_messagewindow(int j, char a)
{
	if (j == 0 && a == 'w')
		ft_printf("ERROR: couldn't use input width, using default width(400)\n");
	else if (j == 0 && a == 'h')
	{
		ft_printf("ERROR: couldn't use input heigth, using default heigth");
		ft_printf("(400)\n");
	}
}

int	check_windowinput(char *argv[], char a, int j)
{
	int	i;
	int	size;

	i = 2;
	size = 0;
	while (argv[i])
	{
		if (argv[i][0] == 'i' && argv[i][1] == 'w' && a == 'w')
			size = ft_atoi(argv[i] + 2);
		else if (argv[i][0] == 'i' && argv[i][1] == 'h' && a == 'h')
			size = ft_atoi(argv[i] + 2);
		if (size)
			break ;
		i++;
	}
	if (!size)
		return (0);
	if (a == 'h' && size > 0 && size <= 1080)
		return (size);
	else if (a == 'w' && size > 0 && size <= 1980)
		return (size);
	print_messagewindow(j, a);
	return (0);
}
