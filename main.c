/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:10:45 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/27 16:47:02 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"

int main() {

	// TESTS DES FONTIONS DE CONVERTIONS -------------------------------------------------------------------

    /*// Test pour %%c avec un caractère non imprimable
    printf("Test pour: %%c avec '\\n' => ");
    fflush(stdout);
    ft_putchar_fd('\n', 1);

    // Test pour %%c avec un caractère spécial
    printf("Test pour: %%c avec '\\0' (null) => ");
    fflush(stdout);
    ft_putchar_fd('\0', 1);

    // Test pour %%%% avec plusieurs signes de pourcentage
    printf("\nTest pour: %%%% avec '%%%%' => ");
    fflush(stdout);
    ft_putchar_fd('%', 1);
    ft_putchar_fd('%', 1);

    // Test pour %%s avec une chaîne vide
    printf("\nTest pour: %%s avec \"\" => ");
    fflush(stdout);
    ft_putstr_fd("", 1);

    // Test pour %%s avec une longue chaîne de caractères
    printf("\nTest pour: %%s avec \"This is a long test string to check the robustness of the function.\" => ");
    fflush(stdout);
    ft_putstr_fd("This is a long test string to check the robustness of the function.", 1);

    // Test pour %%p avec un pointeur NULL
    char *null_ptr = NULL;
    printf("\nTest pour: %%p avec pointeur NULL => ");
    fflush(stdout);
    putptr(null_ptr);

    // Test pour %%p avec un pointeur sur une variable
    int test_int = 42;
    printf("\nTest pour: %%p avec un pointeur vers int => ");
    fflush(stdout);
    putptr(&test_int);

    // Test pour %%d avec l'entier le plus petit possible
    printf("\nTest pour: %%d avec INT_MIN => ");
    fflush(stdout);
    ft_putnbr_fd(-2147483648, 1);

    // Test pour %%i avec un entier positif et zéro
    printf("\nTest pour: %%i avec 0 => ");
    fflush(stdout);
    ft_putnbr_fd(0, 1);

    // Test pour %%u avec la valeur maximale de unsigned int
    unsigned int max_uint = 4294967295U;
    printf("\nTest pour: %%u avec UINT_MAX => ");
    fflush(stdout);
    putnbr_unsigned_fd(max_uint, 1);

    // Test pour %%x avec une valeur hexadécimale élevée
    printf("\nTest pour: %%x avec 0xABCDEF => ");
    fflush(stdout);
    putnbr_hex_fd(0xABCDEF, 1, 'x');

    // Test pour %%X avec une valeur hexadécimale élevée
    printf("\nTest pour: %%X avec 0xABCDEF => ");
    fflush(stdout);
    putnbr_hex_fd(0xABCDEF, 1, 'X');*/

	// TESTS DES FONTIONS DE CONVERTIONS -------------------------------------------------------------------
	char* test_ptr = "427";
	printf("%s %p %s %c %d\n","coucou",test_ptr, "toi", 'i', 1);
	ft_printf("%s %p %s %c %d\n","coucou",test_ptr, "toi", 'i', 1);
	/*printf("\nTest pour: %%p avec un pointeur vers int => ");
	fflush(stdout);
	putptr(&test_ptr);*/
    return 0;
}