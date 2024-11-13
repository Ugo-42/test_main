/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:39:09 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/11/13 10:33:48 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    char			*null_str = NULL;
    char			*str_val = "Hello, World!";
    char			char_val = 'A';
    int				int_val = -42;
    size_t			ft_count, real_count;
    unsigned int	uint_val = 42;
	
	/*
	// to compile with no flags because of warnings 
    char			*void_str = "";

	// Test: null
    ft_count = ft_printf(null_str);
    real_count = printf(null_str);
    printf("ft_printf count: %i, real printf count: %i\n\n", ft_count, real_count);

	// Test: void
    ft_count = ft_printf(void_str);
    real_count = printf(void_str);
    printf("ft_printf count: %i, real printf count: %i\n\n", ft_count, real_count);

	// Test: invalid
    ft_count = ft_printf("%i\n", "hello");
    real_count = printf("%i\n", "hello");
    printf("ft_printf count: %i, real printf count: %i\n\n", ft_count, real_count);

	// Test: string%
    ft_count = ft_printf("Hello,%k World!\n");
    real_count = printf("Hello,%k World!\n");
    printf("ft_printf count: %i, real printf count: %i\n\n", ft_count, real_count);

	// Test: string%
    ft_count = ft_printf("Hello, World!%\n");
    real_count = printf("Hello, World!%\n");
    printf("ft_printf count: %i, real printf count: %i\n\n", ft_count, real_count);

	// Test: string%
    ft_count = ft_printf("%");
    real_count = printf("%");
    printf("ft_printf count: %i, real printf count: %i\n\n", ft_count, real_count);
	*/
	
	// Test: %%
    ft_count = ft_printf("%%c\n");
    real_count = printf("%%c\n");
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

	// Test: %%%%%%%
    ft_count = ft_printf("%%%%%i%%%%c\n", 2147483647);
    real_count = printf("%%%%%i%%%%c\n", 2147483647);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

	// Test: short
    ft_count = ft_printf("%c", char_val);
    real_count = printf("%c", char_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %c (Character)
    ft_count = ft_printf("ft_printf  : %c\n", char_val);
    real_count = printf("real printf: %c\n", char_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %s (String)
    ft_count = ft_printf("ft_printf  : %s\n", str_val);
    real_count = printf("real printf: %s\n", str_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %s null (String)
    ft_count = ft_printf("ft_printf  : %s\n", null_str);
    real_count = printf("real printf: %s\n", null_str);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %s, %s, %s, ... (String)
    ft_count = ft_printf("ft_printf  : %s%s%s%s%s\n", str_val, str_val, str_val, str_val, str_val);
    real_count = printf("real printf: %s%s%s%s%s\n", str_val, str_val, str_val, str_val, str_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %p short (Pointer address)
    ft_count = ft_printf("ft_printf  : %p\n", (void *)1);
    real_count = printf("real printf: %p\n", (void *)1);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %p short (Pointer address)
    ft_count = ft_printf("ft_printf  : %p\n", (void *)15);
    real_count = printf("real printf: %p\n", (void *)15);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %p short (Pointer address)
    ft_count = ft_printf("ft_printf  : %p\n", (void *)666);
    real_count = printf("real printf: %p\n", (void *)666);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %p (Pointer address)
    ft_count = ft_printf("ft_printf  : %p\n", &int_val);
    real_count = printf("real printf: %p\n", &int_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %p (Pointer address)
    ft_count = ft_printf("ft_printf  : %p\n", NULL);
    real_count = printf("real printf: %p\n", NULL);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %p long_max (Pointer address)
    ft_count = ft_printf("ft_printf  : %p\n", (void *)LONG_MAX);
    real_count = printf("real printf: %p\n", (void *)LONG_MAX);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %p long_min (Pointer address)
    ft_count = ft_printf("ft_printf  : %p\n", (void *)LONG_MIN);
    real_count = printf("real printf: %p\n", (void *)LONG_MIN);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %d (Decimal/Integer)
    ft_count = ft_printf("ft_printf  : %d\n", int_val);
    real_count = printf("real printf: %d\n", int_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %i (Integer)
    ft_count = ft_printf("ft_printf  : %i\n", int_val);
    real_count = printf("real printf: %i\n", int_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %u (Unsigned Integer)
    ft_count = ft_printf("ft_printf  : %u\n", uint_val);
    real_count = printf("real printf: %u\n", uint_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %x (Hexadecimal lowercase)
    ft_count = ft_printf("ft_printf  : %x\n", uint_val);
    real_count = printf("real printf: %x\n", uint_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: %X (Hexadecimal uppercase)
    ft_count = ft_printf("ft_printf  : %X\n", uint_val);
    real_count = printf("real printf: %X\n", uint_val);
    printf("ft_printf count: %zu, real printf count: %zu\n\n", ft_count, real_count);

    // Test: all 
    ft_count = ft_printf("ft_printf  : %c | %s | %p | %d | %i | %u | %x | %X\n", char_val, str_val, &str_val, int_val, int_val, uint_val, uint_val, uint_val);
    real_count = printf("real printf: %c | %s | %p | %d | %i | %u | %x | %X\n", char_val, str_val, &str_val, int_val, int_val, uint_val, uint_val, uint_val);
    printf("ft_printf count: %zu, real printf count: %zu\n", ft_count, real_count);
	
	return (0);
}
