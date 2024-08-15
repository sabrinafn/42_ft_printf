/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:57:46 by sabrifer          #+#    #+#             */
/*   Updated: 2024/07/16 12:47:04 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putpointer(void *pointer, int *count)
{
	char				result[17];
	int					remainder;
	int					i;
	unsigned long int	decimal;

	if (pointer == NULL)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	i = 0;
	remainder = 0;
	decimal = (unsigned long int)(pointer);
	while (decimal > 0)
	{
		remainder = decimal % 16;
		decimal = decimal / 16;
		result[i] = BASE16[remainder];
		i++;
	}
	ft_putchar('0', count);
	ft_putchar('x', count);
	while (i-- > 0)
		ft_putchar(result[i], count);
}

void	ft_puthexa(unsigned int decimal, char x, int *count)
{
	char	result[17];
	int		remainder;
	int		i;
	int		j;

	remainder = 0;
	i = 0;
	j = 0;
	if (decimal == 0)
		result[i++] = '0';
	while (decimal > 0)
	{
		remainder = decimal % 16;
		decimal = decimal / 16;
		result[i] = BASE16[remainder];
		i++;
	}
	while (j < i && x == 'X')
	{
		if (result[j] >= 'a' && result[j] <= 'f')
				result[j] -= 32;
		j++;
	}
	while (i-- > 0)
		ft_putchar(result[i], count);
}
