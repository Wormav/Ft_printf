/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:11 by jlorette          #+#    #+#             */
/*   Updated: 2024/10/28 07:52:24 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	putnbr_unsigned_fd(unsigned int n, int *count)
{
	if (n >= 10)
	{
		putnbr_unsigned_fd(n / 10, count);
		putnbr_unsigned_fd(n % 10, count);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		*count += 1;
	}
}

void	putnbr_hex_fd(unsigned int n, int *count, char format)
{
	char	*hex_digits;

	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (n >= 16)
	{
		putnbr_hex_fd(n / 16, count, format);
		putnbr_hex_fd(n % 16, count, format);
	}
	else
	{
		ft_putchar_fd(hex_digits[n], 1);
		*count += 1;
	}
}

void	ft_putnbr_count(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		(*count)++;
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', 1);
		(*count)++;
		return ;
	}
	ft_putnbr_count(n / 10, count);
	ft_putnbr_count(n % 10, count);
}
