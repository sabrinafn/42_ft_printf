/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:24:38 by sabrifer          #+#    #+#             */
/*   Updated: 2023/12/16 18:42:33 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#define BLUE "\e[0;34m"
#define RED "\e[035m"
#define RESET "\e[0m"
#define BWHT "\e[1;37m"

void	test_c(void)
{
	ft_printf(BWHT"TEST WITH A STRING:\n\n"RESET);
	char *str = "Prepare your printf cake by combining finely sifted flour (c), a precise amount of sugar (s), cracked eggs (p), a dash of milk (d), a generous portion of butter (i), a hint of baking powder (u) for dynamic rising, a touch of vanilla extract (x) for a pleasant aroma, and a pinch of salt (%) for balance, mixing until smooth, then bake in a preheated programming environment until your printf statement reaches the desired output consistency, being cautious to avoid overflow and unexpected results, and finally, allow it to cool before serving your delicious and well-formatted printf cake.";
	int i = 0;
	printf(RED"printf: "RESET"\n");
	while (i < strlen(str))
		printf("%c", str[i++]);
	printf(BLUE"\nft_printf: "RESET"\n");
	i = 0;
	while (i < strlen(str))
		ft_printf("%c", str[i++]);
	ft_printf("\n");

	ft_printf(BWHT"\nTESTS WITH RANDOM DATA TYPES:\n\n"RESET);
	ft_printf("-------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%c, %c, %c   "RESET"|\n", "1", '1', 1);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%c, %c, %c   "RESET"|\n", "1", '1', 1);
	ft_printf("-------------------------\n");

	ft_printf("---------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%c, %c  "RESET"|\n", 12345, NULL);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%c, %c  "RESET"|\n", 12345, NULL);
	ft_printf("---------------------\n");
}

void	test_s(void)
{
	ft_printf(BWHT"TEST WITH A STRING:\n\n"RESET);
	printf(RED" printf: "RESET"%s \n", "Prepare your printf cake by combining finely sifted flour (c), a precise amount of sugar (s), cracked eggs (p), a dash of milk (d), a generous portion of butter (i), a hint of baking powder (u) for dynamic rising, a touch of vanilla extract (x) for a pleasant aroma, and a pinch of salt (%) for balance, mixing until smooth, then bake in a preheated programming environment until your printf statement reaches the desired output consistency, being cautious to avoid overflow and unexpected results, and finally, allow it to cool before serving your delicious and well-formatted printf cake.");
	ft_printf(BLUE" ft_printf: "RESET"%s \n", "Prepare your printf cake by combining finely sifted flour (c), a precise amount of sugar (s), cracked eggs (p), a dash of milk (d), a generous portion of butter (i), a hint of baking powder (u) for dynamic rising, a touch of vanilla extract (x) for a pleasant aroma, and a pinch of salt (%) for balance, mixing until smooth, then bake in a preheated programming environment until your printf statement reaches the desired output consistency, being cautious to avoid overflow and unexpected results, and finally, allow it to cool before serving your delicious and well-formatted printf cake.");

	ft_printf(BWHT"IF STR IS EMPTY:\n"RESET);
	ft_printf("-----------------------\n");
	printf(RED"|    printf: "RESET"%s          |\n", "");
	ft_printf(BLUE"| ft_printf: "RESET"%s          |\n", "");
	ft_printf("-----------------------\n");

	ft_printf(BWHT"IF STR IS NULL:\n"RESET);
	char *str = NULL;
	ft_printf("-----------------------\n");
	printf(RED"|    printf: "RESET"%s    |\n", str);
	ft_printf(BLUE"| ft_printf: "RESET"%s    |\n", str);
	ft_printf("-----------------------\n");

	ft_printf(BWHT"IF JUST NULL:\n"RESET);
	ft_printf("-----------------------\n");
	printf(RED"|    printf: "RESET"%s    |\n", NULL);
	ft_printf(BLUE"| ft_printf: "RESET"%s    |\n", NULL);
	ft_printf("-----------------------\n");

	//next one is about passing a different data type than %s
	//one function has to be called while the other is commented out, 
	//the program quits after the first segfault
	/*
	ft_printf("-----------------------\n");
	printf(RED"| printf: "RESET"%s |\n", 12345);
	//ft_printf(BLUE"| ft_printf: "RESET"%s |\n", 12345);
	ft_printf("-----------------------\n");
	*/
}

void	test_p(void)
{
	ft_printf("arg: -1\n");	
	ft_printf("----------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%p  "RESET"|\n", -1);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%p  "RESET"|\n", -1);
	ft_printf("----------------------------\n");
	
	ft_printf("arg: char *str = NULL\n");	
	char *str = NULL;
	ft_printf("--------------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%p  "RESET"|\n", &str);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%p  "RESET"|\n", &str);
	ft_printf("--------------------------------\n");
	
	ft_printf("arg: char *ptr = str\n");	
	char *ptr = str;
	ft_printf("-----------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%p  "RESET"|\n", ptr);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%p  "RESET"|\n", ptr);
	ft_printf("-----------------------\n");
	
	ft_printf("arg: void * = NULL\n");	
	void *vp = NULL;
	ft_printf("-----------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%p  "RESET"|\n", vp);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%p  "RESET"|\n", vp);
	ft_printf("-----------------------\n");
}

void	test_i_d(char i_d)
{
	if (i_d == 'i') //tests if arg is 'i'
	{
		ft_printf(BWHT"TEST WITH INT_MIN AND INT_MAX:\n"RESET);
		ft_printf("----------------------------\n");
		printf("|"RED"   PRINTF: "RESET BWHT"%i    "RESET"|\n", INT_MIN);
		printf("|"RED"   PRINTF: "RESET BWHT"%i      "RESET"|\n", INT_MAX);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%i"RESET"|\n", INT_MIN);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%i  "RESET"|\n", INT_MAX);
		ft_printf("----------------------------\n");
		ft_printf(BWHT"TEST WITH -1, 0 and 1:\n"RESET);
		for(int i = -1; i < 2; i++)
		{
			ft_printf("----------------------------\n");
			printf("|"RED"   PRINTF:    "RESET BWHT"%i  "RESET"|\n", i);
			ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%i  "RESET"|\n", i);
			ft_printf("----------------------------\n");
		}
		ft_printf(BWHT"TEST WITH LLONG_MIN AND LLONG_MAX:\n"RESET);
		ft_printf("----------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%i  "RESET"|\n", LLONG_MIN);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%i  "RESET"|\n", LLONG_MIN);
		ft_printf("----------------------------\n");
		ft_printf("----------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%i  "RESET"|\n", LLONG_MAX);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%i  "RESET"|\n", LLONG_MAX);
		ft_printf("----------------------------\n");
	}
	if (i_d == 'd') //tests if arg is 'd'
	{
		ft_printf(BWHT"TEST WITH INT_MIN AND INT_MAX:\n"RESET);
		ft_printf("----------------------------\n");
		printf("|"RED"   PRINTF: "RESET BWHT"%d    "RESET"|\n", INT_MIN);
		printf("|"RED"   PRINTF: "RESET BWHT"%d      "RESET"|\n", INT_MAX);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%d"RESET"|\n", INT_MIN);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%d  "RESET"|\n", INT_MAX);
		ft_printf("----------------------------\n");
		ft_printf(BWHT"TEST WITH -1, 0 and 1:\n"RESET);
		for(int i = -1; i < 2; i++)
		{
			ft_printf("----------------------------\n");
			printf("|"RED"   PRINTF:    "RESET BWHT"%d  "RESET"|\n", i);
			ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%d  "RESET"|\n", i);
			ft_printf("----------------------------\n");
		}
		ft_printf(BWHT"TEST WITH LLONG_MIN AND LLONG_MAX:\n"RESET);
		ft_printf("----------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%d  "RESET"|\n", LLONG_MIN);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%d  "RESET"|\n", LLONG_MIN);
		ft_printf("----------------------------\n");
		ft_printf("----------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%d  "RESET"|\n", LLONG_MAX);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%d  "RESET"|\n", LLONG_MAX);
		ft_printf("----------------------------\n");
	}
}

void	test_u(void)
{
	ft_printf(BWHT"TEST WITH INT_MIN AND INT_MAX:\n"RESET);
	ft_printf("----------------------------\n");
	printf("|"RED"   PRINTF: "RESET BWHT"%u    "RESET"|\n", INT_MIN);
	printf("|"RED"   PRINTF: "RESET BWHT"%u      "RESET"|\n", INT_MAX);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%u"RESET"|\n", INT_MIN);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%u  "RESET"|\n", INT_MAX);
	ft_printf("----------------------------\n");
	ft_printf(BWHT"TEST WITH -1, 0 and 1:\n"RESET);
	for(int i = -1; i < 2; i++)
	{
		ft_printf("----------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%u  "RESET"|\n", i);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%u  "RESET"|\n", i);
		ft_printf("----------------------------\n");
	}
	ft_printf(BWHT"TEST WITH LLONG_MIN AND LLONG_MAX:\n"RESET);
	ft_printf("----------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%u  "RESET"|\n", LLONG_MIN);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%u  "RESET"|\n", LLONG_MIN);
	ft_printf("----------------------------\n");
	ft_printf("----------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%u  "RESET"|\n", LLONG_MAX);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%u  "RESET"|\n", LLONG_MAX);
	ft_printf("----------------------------\n");
}

void	test_x_X(char x_X)
{
	if (x_X == 'x')
	{
		ft_printf(BWHT"TEST WITH VALUES: -3 TO 1:\n"RESET);
		for (int i = -3; i < 2; i++)
		{
			ft_printf("---------------------------\n");
			printf("|"RED"   PRINTF:    "RESET BWHT"%x  "RESET"|\n", i);
			ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%x  "RESET"|\n", i);
			ft_printf("---------------------------\n");
		}
		ft_printf(BWHT"TEST WITH LLONG_MIN:\n"RESET);
		ft_printf("---------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%x  "RESET"|\n", LONG_MIN);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%x  "RESET"|\n", LONG_MIN);
		ft_printf("---------------------------\n");
		
		ft_printf(BWHT"TEST WITH 1234:\n"RESET);
		ft_printf("---------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%x  "RESET"|\n", 1234);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%x  "RESET"|\n", 1234);
		ft_printf("---------------------------\n");
	}
	if (x_X == 'X')
	{
		ft_printf(BWHT"TEST WITH VALUES: -3 TO 1:\n"RESET);
		for (int i = -3; i < 2; i++)
		{
			ft_printf("---------------------------\n");
			printf("|"RED"   PRINTF:    "RESET BWHT"%X  "RESET"|\n", i);
			ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%X  "RESET"|\n", i);
			ft_printf("---------------------------\n");
		}
		ft_printf(BWHT"TEST WITH LLONG_MIN:\n"RESET);
		ft_printf("---------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%X  "RESET"|\n", LONG_MIN);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%X  "RESET"|\n", LONG_MIN);
		ft_printf("---------------------------\n");
		
		ft_printf(BWHT"TEST WITH 1234:\n"RESET);
		ft_printf("---------------------------\n");
		printf("|"RED"   PRINTF:    "RESET BWHT"%X  "RESET"|\n", 1234);
		ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%X  "RESET"|\n", 1234);
		ft_printf("---------------------------\n");
	}
}

void	test_percent(void)
{
	
	ft_printf(BWHT"TEST WITH 1%%:\n"RESET);
	ft_printf("---------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%  "RESET"|\n");
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%  "RESET"|\n");
	ft_printf("---------------------------\n");

	ft_printf(BWHT"TEST WITH 1%% + nullchar:\n"RESET);
	ft_printf("---------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%");
	printf(RESET"|\n");
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%");
	ft_printf(RESET"|\n");
	ft_printf("---------------------------\n");

	ft_printf(BWHT"TEST WITH 2%%:\n"RESET);
	ft_printf("---------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%%  "RESET"|\n");
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%%  "RESET"|\n");
	ft_printf("---------------------------\n");
	
	ft_printf(BWHT"TEST WITH 3%%:\n"RESET);
	ft_printf("---------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%%%  "RESET"|\n");
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%%%  "RESET"|\n");
	ft_printf("---------------------------\n");

	ft_printf(BWHT"TEST WITH 10%%:\n"RESET);
	ft_printf("---------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%%%%%%%%%%  "RESET"|\n");
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%%%%%%%%%%  "RESET"|\n");
	ft_printf("---------------------------\n");

	ft_printf(BWHT"TEST WITH 23%%:\n"RESET);
	ft_printf("---------------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%%%%%%%%%%%%%%%%%%%%%%%  "RESET"|\n");
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%%%%%%%%%%%%%%%%%%%%%%%  "RESET"|\n");
	ft_printf("---------------------------\n");
}

void	test_return_value(void)
{
	ft_printf(BWHT"TEST WITH A STRING:\n\n"RESET);
	int i = printf("%s\n", "Prepare your printf cake by combining finely sifted flour (c), a precise amount of sugar (s), cracked eggs (p), a dash of milk (d), a generous portion of butter (i), a hint of baking powder (u) for dynamic rising, a touch of vanilla extract (x) for a pleasant aroma, and a pinch of salt (%) for balance, mixing until smooth, then bake in a preheated programming environment until your printf statement reaches the desired output consistency, being cautious to avoid overflow and unexpected results, and finally, allow it to cool before serving your delicious and well-formatted printf cake.");
	int j = ft_printf("%s\n", "Prepare your printf cake by combining finely sifted flour (c), a precise amount of sugar (s), cracked eggs (p), a dash of milk (d), a generous portion of butter (i), a hint of baking powder (u) for dynamic rising, a touch of vanilla extract (x) for a pleasant aroma, and a pinch of salt (%) for balance, mixing until smooth, then bake in a preheated programming environment until your printf statement reaches the desired output consistency, being cautious to avoid overflow and unexpected results, and finally, allow it to cool before serving your delicious and well-formatted printf cake.");

	ft_printf(BWHT"RETURN VALUE:\n"RESET);
	ft_printf("---------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%d  "RESET"|\n", i);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%d  "RESET"|\n", j);
	ft_printf("---------------------\n");
	
	ft_printf(BWHT"\nTEST WITH ANOTHER STRING:\n\n"RESET);
	i = printf("hi\n");
	j = ft_printf("hi\n");

	ft_printf(BWHT"RETURN VALUE:\n"RESET);
	ft_printf("---------------------\n");
	printf("|"RED"   PRINTF:    "RESET BWHT"%d  "RESET"|\n", i);
	ft_printf("|"BLUE"   FT_PRINTF: "RESET BWHT"%d  "RESET"|\n", j);
	ft_printf("---------------------\n");
	
}

void	how_to_use(void)
{
	ft_printf("Program use: ./a.out	format specifier.\n");
	ft_printf("\t-----------------------\n");
	ft_printf("\t| FORMAT SPECIFIERS:  |\n");
	ft_printf("\t-----------------------\n");
	ft_printf(BWHT"c: "RESET"%%c Prints a single character.\n");
	ft_printf(BWHT"s: "RESET"%%s Prints a string (as defined by the common C convention).\n");
	ft_printf(BWHT"p: "RESET"%%p The void * pointer argument has to be printed in hexadecimal format.\n");
	ft_printf(BWHT"d: "RESET"%%d Prints a decimal (base 10) number.\n");
	ft_printf(BWHT"i: "RESET"%%i Prints an integer in base 10.\n");
	ft_printf(BWHT"u: "RESET"%%u Prints an unsigned decimal (base 10) number.\n");
	ft_printf(BWHT"x: "RESET"%%x Prints a number in hexadecimal (base 16) lowercase format.\n");
	ft_printf(BWHT"X: "RESET"%%X Prints a number in hexadecimal (base 16) uppercase format.\n");
	ft_printf(BWHT"%%: "RESET"%%%% Prints a percent sign.\n");
	ft_printf(BWHT"return: "RESET"Prints return value.\n");
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		how_to_use();
		return 1;
	}
	if (strcmp(av[1], "c") == 0)
		test_c();
	else if (strcmp(av[1], "s") == 0)
		test_s();
	else if (strcmp(av[1], "p") == 0)
		test_p();
	else if (strcmp(av[1], "d") == 0 || strcmp(av[1], "i") == 0)
		test_i_d(av[1][0]);
	else if (strcmp(av[1], "u") == 0)
		test_u();
	else if (strcmp(av[1], "x") == 0 || strcmp(av[1], "X") == 0)
		test_x_X(av[1][0]);
	else if (strcmp(av[1], "%%") == 0)
		test_percent();
	else if (strcmp(av[1], "return") == 0)
		test_return_value();
	else
		how_to_use();

	return (0);
}
