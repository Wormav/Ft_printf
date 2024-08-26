/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:35:12 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/26 18:26:02 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putptr(void *ptr)
{
	int	result;

	result = write(1, "0x", 2);
	result += putnbr_hex((unsigned long)ptr);
	return (result);
}
