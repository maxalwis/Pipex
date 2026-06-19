/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:44:16 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:13:37 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf_strlen(char *str);
int	check_base(char *base);
int	ft_putnbr_base(long nbr, char *base);
int	ft_putnbr_base_pointer(unsigned long nbr, char *base);
int	ft_printf(const char *format, ...);
int	handle_pointer(void *ptr);
int	print_format(char specifier, va_list arg);

#endif