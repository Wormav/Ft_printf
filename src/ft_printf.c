/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:05:29 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/27 21:14:57 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "../libft/libft.h"

static void decimal_gestion(char format, va_list args, int *count)
{
	if (format == 'd' || format == 'i')
		ft_putnbr_count(va_arg(args, int), count);
	else if (format == 'u')
		putnbr_unsigned_fd(va_arg(args, unsigned int), count);
	else if (format == 'x' || format == 'X')
		putnbr_hex_fd(va_arg(args, unsigned int), count, format);
	else if (format == 'p')
		*count += putptr(va_arg(args, void *));
}

static void string_gestion(char format, va_list args, int *count)
{
	char *s;

	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*count)++;
	}
	else if (format == 's')
	{
		s = va_arg(args, char *);
		if (s)
		{
			ft_putstr_fd(s, 1);
			(*count) += ft_strlen(s);
		}
		else
			return ;
	}
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int count;
	char *s;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			if (*str == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
			}
			else if (*str == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				count++;
			}
			else if (*str == 's')
			{
				s = va_arg(args, char *);
				ft_putstr_fd(s, 1);
				count += ft_strlen(s);
			}
			else if (*str == 'p')
				count += putptr(va_arg(args, void *));
			else if (*str == 'd' || *str == 'i')
				ft_putnbr_count(va_arg(args, int), &count);
			else if (*str == 'u')
				putnbr_unsigned_fd(va_arg(args, unsigned int), &count);
			else if (*str == 'x')
				putnbr_hex_fd(va_arg(args, unsigned int), &count, 'x');
			else if (*str == 'X')
				putnbr_hex_fd(va_arg(args, unsigned int), &count, 'X');
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}