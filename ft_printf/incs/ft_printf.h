/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:34:51 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/28 20:40:47 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_len(long int n);
int	write_string(char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_unsignedint(unsigned int number);
int	ft_printhexa(unsigned int n, int m);
int	ft_printpointer(unsigned long long int addr);
int	ft_printf(const char *str, ...);
int	ft_args(va_list args, char c);
int	ft_printhexapointer(unsigned long long int n);
int	ft_longhex(unsigned long long int n);
int	ft_printfloat(double number);

#endif
