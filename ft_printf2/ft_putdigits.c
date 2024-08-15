/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:57:04 by sabrifer          #+#    #+#             */
/*   Updated: 2024/07/15 12:57:33 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putid(int i, int *count)
{
	long int	num;

	num = i;
	if (num < 0)
	{
		num = -num;
		ft_putchar('-', count);
	}
	if (num > 9)
	{
		ft_putid(num / 10, count);
		ft_putid(num % 10, count);
	}
	else
		ft_putchar(num + '0', count);
}

void	ft_putuint(unsigned int ui, int *count)
{
	if (ui > 9)
	{
		ft_putuint(ui / 10, count);
		ft_putuint(ui % 10, count);
	}
	else
		ft_putchar(ui + '0', count);
}
