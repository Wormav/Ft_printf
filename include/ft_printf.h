/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:31:25 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/27 15:05:49 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char *str, ...);
void	putnbr_hex_fd(unsigned int n, int fd, char format);
void	putnbr_unsigned_fd(unsigned int n, int fd);
int		putptr(void *ptr);


#endif