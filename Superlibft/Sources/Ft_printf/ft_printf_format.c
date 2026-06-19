/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:57:38 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:14:57 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_pointer(unsigned long nbr, char *base)
{
	int	base_len;
	int	count;

	count = 0;
	base_len = ft_printf_strlen(base);
	if (!check_base(base))
		return (0);
	if (nbr >= (unsigned long)base_len)
		count += ft_putnbr_base_pointer(nbr / base_len, base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}

int	handle_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base_pointer((unsigned long)ptr, "0123456789abcdef");
	}
	return (count);
}

int	print_format(char specifier, va_list arg)
{
	int			count;

	count = 0;
	if (specifier == '%')
		count += ft_putchar('%');
	else if (specifier == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr_base(va_arg(arg, int), "0123456789");
	else if (specifier == 'x')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (specifier == 'u')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789");
	else if (specifier == 'p')
		count += handle_pointer(va_arg(arg, void *));
	else
		return (-1);
	return (count);
}
