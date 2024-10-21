/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:33:11 by jlorette          #+#    #+#             */
/*   Updated: 2024/10/19 22:53:44 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	putnbr_hex(unsigned long n)
{
	char	*hex_digits;
	int		result;

	hex_digits = "0123456789abcdef";
	result = 0;
	if (n >= 16)
		result += putnbr_hex(n / 16);
	result += write(1, &hex_digits[n % 16], 1);
	return (result);
}

int	putptr(void *ptr)
{
	int	result;

	result = write(1, "0x", 2);
	result += putnbr_hex((unsigned long)ptr);
	return (result);
}

void	print_pourcent(int *count)
{
	ft_putchar_fd('%', 1);
	(*count)++;
}
