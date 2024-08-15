/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:24:38 by sabrifer          #+#    #+#             */
/*   Updated: 2023/12/16 19:41:57 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_data_type(const char *str, int i, va_list args, int *count)
{
	if (str[i] == 'c')
		put_single_char(va_arg(args, int), count);
	else if (str[i] == 's')
		put_full_str(va_arg(args, char *), count);
	else if (str[i] == 'p')
		put_address_ptr(va_arg(args, void *), count);
	else if (str[i] == 'd' || str[i] == 'i')
		put_nbr_id(va_arg(args, int), count);
	else if (str[i] == 'u')
		put_unsigned_decimal(va_arg(args, unsigned int), count);
	else if (str[i] == 'x' || str[i] == 'X')
		put_nbr_in_hex(va_arg(args, unsigned int), str[i], count);
	else if (str[i] == '%')
		put_single_char('%', count);
	else
		put_single_char('%', count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count_return;
	va_list	args;

	va_start(args, str);
	i = 0;
	count_return = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			check_data_type(str, i + 1, args, &count_return);
			i++;
		}
		else
			put_single_char(str[i], &count_return);
		i++;
	}
	va_end(args);
	return (count_return);
}
