/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:11 by jlorette          #+#    #+#             */
/*   Updated: 2024/10/28 07:52:02 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_count(int n, int *count);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
void	print_pourcent(int *count);
void	putnbr_hex_fd(unsigned int n, int *count, char format);
void	putnbr_unsigned_fd(unsigned int n, int *count);
int		putptr(void *ptr);

#endif
