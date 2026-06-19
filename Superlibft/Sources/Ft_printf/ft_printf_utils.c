/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:25:38 by maalwis           #+#    #+#             */
/*   Updated: 2025/04/02 00:57:32 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (s[i])
	{
		write(1, &s[i++], 1);
		count++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || ft_printf_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(long nbr, char *base)
{
	int	base_len;
	int	count;

	count = 0;
	base_len = ft_printf_strlen(base);
	if (!check_base(base))
		return (0);
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}
