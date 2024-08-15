/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:13:19 by sabrifer          #+#    #+#             */
/*   Updated: 2024/07/16 14:44:15 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_percent(va_list *list, char c, int *count_chars)
{
	if (c == 'c')
		ft_putchar(va_arg(*list, int), count_chars);
	else if (c == 's')
		ft_putstr(va_arg(*list, char *), count_chars);
	else if (c == 'p')
		ft_putpointer(va_arg(*list, void *), count_chars);
	else if (c == 'i' || c == 'd')
		ft_putid(va_arg(*list, int), count_chars);
	else if (c == 'u')
		ft_putuint(va_arg(*list, unsigned int), count_chars);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(*list, unsigned int), c, count_chars);
	else if (c == '%')
		ft_putchar('%', count_chars);
}

int	ft_printf(const char *args, ...)
{
	va_list	list;
	int		i;
	int		total_chars;

	if (args == NULL)
		return (-1);
	i = 0;
	total_chars = 0;
	va_start(list, args);
	while (args[i])
	{
		if (args[i] == '%')
			check_percent(&list, args[++i], &total_chars);
		else
			ft_putchar(args[i], &total_chars);
		i++;
	}
	va_end(list);
	return (total_chars);
}
