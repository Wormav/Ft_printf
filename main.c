/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:10:45 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/30 13:09:25 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

int main() {
	int return_printf = 0;
	int return_ft_printf = 0;
	char* test_ptr = "427";
	return_printf = printf("%i\n", -2147483648);
	return_ft_printf = ft_printf("%i\n", -2147483648);

	printf("%d\n", return_printf);
	printf("%d\n", return_ft_printf);
    return 0;
}