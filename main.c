/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:10:45 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/29 21:59:49 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"

int main() {
	int return_printf = 0;
	int return_ft_printf = 0;
	char* test_ptr = "427";
	return_printf = printf("%s %p %s %c %d test %i %u %x %X %%\n","coucou",test_ptr, "toi", 'i', 42453, -12, 4294967295U, 5678, 5678);
	return_ft_printf = ft_printf("%s %p %s %c %d test %i %u %x %X %%\n","coucou",test_ptr, "toi", 'i', 42453, -12, 4294967295U, 5678, 5678);

	printf("%d\n", return_printf);
	printf("%d\n", return_ft_printf);
    return 0;
}