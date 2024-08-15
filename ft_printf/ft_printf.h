/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:25:05 by sabrifer          #+#    #+#             */
/*   Updated: 2023/12/16 19:40:02 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define BASE16 "0123456789abcdef"

int		ft_printf(const char *str, ...);
void	check_data_type(const char *str, int i, va_list args, int *count);
void	put_single_char(int c, int *count);
void	put_full_str(char *str, int *count);
void	put_address_ptr(void *ptr, int *count);
void	put_nbr_id(int n, int *count);
void	put_unsigned_decimal(unsigned int i, int *count);
void	put_nbr_in_hex(unsigned int dec, char check_x, int *count);

#endif
