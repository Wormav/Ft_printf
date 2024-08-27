/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:10:45 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/27 18:14:43 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"

int main() {
	char* test_ptr = "427";
	printf("%s %p %s %c %d test %i %u %x %X\n","coucou",test_ptr, "toi", 'i', 42453, -12, 4294967295U, 5678, 5678);
	ft_printf("%s %p %s %c %d test %i %u %x %X\n","coucou",test_ptr, "toi", 'i', 42453, -12, 4294967295U, 5678, 5678);
    return 0;
}