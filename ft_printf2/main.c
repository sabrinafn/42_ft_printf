/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:30:04 by sabrifer          #+#    #+#             */
/*   Updated: 2024/07/16 14:42:59 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_printf(const char *args, ...);

void	test_c(void)
{
	//SAME ERROR = EMPTY CHARACTER CONSTANT
	//printf("og empty: |%c|\n", '');
	//ft_printf("ft empty: |%c|\n", '');

	//BOTH PRINT, BUT ERROR MESSAGE FOR PRINTF	
	//printf("og str: |%c|\n", "iiiiiiii");
	ft_printf("ft str: |%c|\n", "iiiiiii");
	
	//DIGITS FAR FROM ASCII TABLE. BOTH PRINT '??????'
	//printf("og str: |%c|\n", 999);
	//ft_printf("ft str: |%c|\n", 999);

	//normal
	//printf("og str: |%c|\n", 115);
	//ft_printf("ft str: |%c|\n", 115);
}

void	test_s(void)
{
	printf("   printf 1: %s\n", "teste1\t\taaa");
	ft_printf("ft_printf 1: %s\n", "teste1\t\taaa");

	printf("   printf 2: %s\n", "");
	ft_printf("ft_printf 2: %s\n", "");

	char	*str = NULL;

	printf("printf return value: %d\n", printf("   printf 3: %s\n", str));
	ft_printf("ft_printf return value: %d\n", ft_printf("ft_printf 3: %s\n", str));

	printf("   printf 4: %s\n", "");
	ft_printf("ft_printf 4: %s\n", "");

	printf("   printf 5: %s\n", "String with non-printable characters \x01\x02\x03");
	ft_printf("ft_printf 5: %s\n", "String with non-printable characters \x01\x02\x03");
}

void	test_p(void)
{
	char c = 42;
	printf("return value og: %i\n", printf("   printf 1: |%p|\n", &c));
	ft_printf("return value ft: %i\n", ft_printf("ft_printf 1: |%p|\n", &c));

	int	*ptr = NULL;
	printf("return value og: %i\n", printf("   printf 2: |%p|\n", &ptr));
	ft_printf("return value ft: %i\n", ft_printf("ft_printf 2: |%p|\n", &ptr));

	int arr[7] = {-1, 1, 15, 16, 17, 0, 0};

	for (int i = 0; i < 7; i++)
	{
		printf("   printf: |%p|\n", &arr[i]);
		ft_printf("ft_printf: |%p|\n", &arr[i]);
	}

	//LONG_MIN, LONG_MAX, INT_MIN, INT_MAX, ULONG_MAX, -ULONG_MAX

	printf("   printf: |%p|\n", (void *)LONG_MIN);
	ft_printf("ft_printf: |%p|\n", (void *)LONG_MIN);
	
	printf("   printf: |%p|\n", (void *)LONG_MAX);
	ft_printf("ft_printf: |%p|\n", (void *)LONG_MAX);

	printf("   printf: |%p|\n", (void *)INT_MIN);
	ft_printf("ft_printf: |%p|\n", (void *)INT_MIN);

	printf("   printf: |%p|\n", (void *)INT_MAX);
	ft_printf("ft_printf: |%p|\n", (void *)INT_MAX);

	printf("   printf: |%p|\n", (void *)ULONG_MAX);
	ft_printf("ft_printf: |%p|\n", (void *)ULONG_MAX);

	printf("   printf: |%p|\n", (void *)-ULONG_MAX);
	ft_printf("ft_printf: |%p|\n", (void *)-ULONG_MAX);
}

void	test_id(void)
{
	int	arr[7] = {42, 0, -42, INT_MAX, INT_MIN, 00000042, 0042};

	printf("with %%i: \n");
	for (int i = 0; i < 7; i++)
	{
		printf("   printf %i: |%i|\n", i, arr[i]);
		ft_printf("ft_printf %i: |%i|\n", i, arr[i]);
	}

	printf("with %%d: \n");
	
	for (int d = 0; d < 7; d++)
	{
		printf("   printf %d: |%d|\n", d, arr[d]);
		ft_printf("ft_printf %d: |%d|\n", d, arr[d]);
	}
}

void	test_u(void)
{
	int	arr[8] = {42, 0, -42, INT_MAX, INT_MIN, 00000042, UINT_MAX, UINT_MAX - 1};

	for (int i = 0; i < 8; i++)
	{
		printf("   printf %i: |%u|\n", i, arr[i]);
		ft_printf("ft_printf %i: |%u|\n", i, arr[i]);
	}
}

void	test_x(void)
{

	int	arr[8] = {42, 0, -42, INT_MAX, INT_MIN, 00000042, UINT_MAX, UINT_MAX - 1};

	for (int i = 0; i < 8; i++)
	{
		printf("   printf %i: |%x|\n", i, arr[i]);
		ft_printf("ft_printf %i: |%x|\n", i, arr[i]);
	}
	printf("   printf 8: |%x|\n", 0);
	ft_printf("ft_printf 8: |%x|\n", 0);

	for (int i = 0; i < 8; i++)
	{
		printf("   printf %i: |%X|\n", i, arr[i]);
		ft_printf("ft_printf %i: |%X|\n", i, arr[i]);
	}
}

int	main(void)
{
	//test_c();
	//test_s();
	//test_p();
	//test_id();
	//test_u();
	//test_x();

//	printf("%c - %c - %c - %x\n\n", 'a', 'b', 'c', "abc");
//	ft_printf("%c - %c - %c - %x\n\n", 'a', 'b', 'c', "abc");
//	printf("%c - %c - %c\n\n", 'a', 'b', 'c', "abc");
//	ft_printf("%c - %c - %c\n\n", 'a', 'b', 'c', "abc");
//	printf("%c - %c - %s - %c\n\n", 'a', 'b', 'c', "abc");
//	ft_printf("%c - %c - %s - %c\n\n", 'a', 'b', 'c', "abc");

	printf("og digit: %d\n", printf(NULL));
	ft_printf("ft digit: %d\n", ft_printf(NULL));

}
