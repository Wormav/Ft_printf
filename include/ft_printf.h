/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:31:25 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/30 13:00:40 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	putnbr_hex_fd(unsigned int n, int *count, char format);
void	putnbr_unsigned_fd(unsigned int n, int *count);
void	ft_putnbr_count(int n, int *count);
int		putptr(void *ptr);
void	print_pourcent(int *count);
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);


#endif