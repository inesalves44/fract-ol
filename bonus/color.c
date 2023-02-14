/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:03:16 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/11 10:03:17 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	get_r(int m)
{
	int	color;

	color = (int)(0x00FF0000 - 0x00FF0000 * 20 * m);
	return (color);
}

int	get_g(int m)
{
	int	color;

	color = (int)(0x0000FF00 + 0x0000FF00 * 20 * m);
	return (color);
}

int	get_b(int m)
{
	int	color;

	color = (int)(0x000000FF + 0x000000FF * 20 * m);
	return (color);
}
