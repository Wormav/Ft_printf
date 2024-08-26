/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:57:17 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/26 19:02:36 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		putnbr_unsigned_fd(n / 10, fd);
		putnbr_unsigned_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	putnbr_hex_fd(unsigned int n, int fd, char format) {
	char	*hex_digits;

	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (n >= 16)
	{
		putnbr_hex_fd(n / 16, fd, format);
		putnbr_hex_fd(n % 16, fd, format);
	}
	else
		ft_putchar_fd(hex_digits[n], fd);
}