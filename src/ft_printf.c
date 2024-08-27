/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:05:29 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/27 18:10:33 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "../libft/libft.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	int target;
	char *s;

	if (!str)
		return (-1);
	va_start(args, str);
	target = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			if (*str == '%')
			{
				ft_putchar_fd('%', 1);
				target++;
			}
			else if (*str == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				target++;
			}
			else if (*str == 's')
			{
				s = va_arg(args, char *);
				ft_putstr_fd(s, 1);
				target += ft_strlen(s);
			}
			else if (*str == 'p')
				target += putptr(va_arg(args, void *));
			else if (*str == 'd' || *str == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*str == 'u')
				putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
			else if (*str == 'x')
				putnbr_hex_fd(va_arg(args, unsigned int), 1, 'x');
			else if (*str == 'X')
				putnbr_hex_fd(va_arg(args, unsigned int), 1, 'X');
		}
		else
		{
			ft_putchar_fd(*str, 1);
			target++;
		}
		str++;
	}
	va_end(args);
	return (target);
}