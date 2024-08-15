/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:24:38 by sabrifer          #+#    #+#             */
/*   Updated: 2023/12/16 22:49:30 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		put_single_char(nbr + '0', count);
}

void	put_unsigned_decimal(unsigned int i, int *count)
{
	if (i > 9)
	{
		put_unsigned_decimal(i / 10, count);
		put_unsigned_decimal(i % 10, count);
	}
	else
		put_single_char(i + '0', count);
}
