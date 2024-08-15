/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:15:01 by sabrifer          #+#    #+#             */
/*   Updated: 2024/07/16 12:45:02 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define BASE16 "0123456789abcdef"

void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putpointer(void *pointer, int *count);
void	ft_putid(int i, int *count);
void	ft_putuint(unsigned int ui, int *count);
void	ft_puthexa(unsigned int decimal, char x, int *count);
void	check_percent(va_list *lista, char c, int *count_chars);
int		ft_printf(const char *args, ...);

#endif
