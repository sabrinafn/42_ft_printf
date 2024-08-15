/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:24:38 by sabrifer          #+#    #+#             */
/*   Updated: 2023/12/16 22:20:13 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_single_char(int c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void	put_full_str(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		put_full_str("(null)", count);
		return ;
	}
	while (str[i])
	{
		put_single_char(str[i], count);
		i++;
	}
}

void	put_address_ptr(void *ptr, int *count)
{
	int					i;
	int					remainder;
	char				hex_value[16];
	unsigned long int	decimal;

	if (ptr == NULL)
	{
		put_full_str("(nil)", count);
		return ;
	}
	decimal = (unsigned long int)ptr;
	i = 0;
	while (decimal > 0)
	{
		remainder = decimal % 16;
		decimal = decimal / 16;
		hex_value[i] = BASE16[remainder];
		i++;
	}
	put_single_char('0', count);
	put_single_char('x', count);
	while (i-- > 0)
		put_single_char(hex_value[i], count);
}

void	put_nbr_id(int n, int *count)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		put_single_char('-', count);
	}
	if (nbr > 9)
	{
		put_nbr_id(nbr / 10, count);
		put_nbr_id(nbr % 10, count);
	}
	else
	{
		put_single_char(nbr + '0', count);
	}
}

void	put_unsigned_decimal(unsigned int i, int *count)
{
	if (i > 9)
	{
		put_unsigned_decimal(i / 10, count);
		put_unsigned_decimal(i % 10, count);
	}
	else
	{
		put_single_char(i + '0', count);
	}
}

void	put_nbr_in_hex(unsigned int decimal, char check_x, int *count)
{
	int		i;
	int		j;
	int		remainder;
	char	hex_value[9];

	i = 0;
	j = 0;
	while (decimal > 0)
	{
		remainder = decimal % 16;
		decimal = decimal / 16;
		hex_value[i] = BASE16[remainder];
		i++;
	}
	if (i == 0)
		hex_value[i++] = '0';
	while (j < i && check_x == 'X')
	{
		if (hex_value[j] >= 'a' && hex_value[j] <= 'f')
			hex_value[j] -= 32;
		j++;
	}
	while (i-- > 0)
		put_single_char(hex_value[i], count);
}
