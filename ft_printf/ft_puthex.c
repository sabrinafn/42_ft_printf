/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:24:38 by sabrifer          #+#    #+#             */
/*   Updated: 2023/12/16 22:43:51 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
