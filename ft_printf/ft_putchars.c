/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:24:38 by sabrifer          #+#    #+#             */
/*   Updated: 2023/12/16 22:43:04 by sabrifer         ###   ########.fr       */
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
