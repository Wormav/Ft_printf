/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:39:44 by jlorette          #+#    #+#             */
/*   Updated: 2024/10/30 14:45:14 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	string_gestion(char format, va_list *args, int *count)
{
	char	*s;

	if (format == 'c')
	{
		ft_putchar_fd(va_arg(*args, int), 1);
		(*count)++;
	}
	else
	{
		s = va_arg(*args, char *);
		if (!s)
			s = "(null)";
		ft_putstr_fd(s, 1);
		(*count) += ft_strlen(s);
	}
}

static	void	decimal_gestion(char format, va_list *args, int *count)
{
	void	*ptr;

	if (format == 'p')
	{
		ptr = va_arg(*args, void *);
		if (!ptr)
		{
			ft_putstr_fd("(nil)", 1);
			*count += 5;
		}
		else
			*count += putptr(ptr);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr_count(va_arg(*args, int), count);
	else if (format == 'u')
		putnbr_unsigned_fd(va_arg(*args, unsigned int), count);
	else if (format == 'x')
		putnbr_hex_fd(va_arg(*args, unsigned int), count, 'x');
	else if (format == 'X')
		putnbr_hex_fd(va_arg(*args, unsigned int), count, 'X');
}

static	void	process(char format, va_list *args, int *count)
{
	if (format == '%')
		print_pourcent(count);
	else if (format == 'c' || format == 's')
		string_gestion(format, args, count);
	else if (format == 'd' || format == 'i' || format == 'u' || format == 'x'
		|| format == 'p' || format == 'X')
		decimal_gestion(format, args, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			process(*str, &args, &count);
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
