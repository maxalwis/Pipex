/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:42 by maalwis           #+#    #+#             */
/*   Updated: 2024/12/23 17:06:09 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += print_format(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
	long a = LONG_MAX;

	ft_printf("Caractere : %c\n", 'A');
	printf("Vrai printf -> Caractere : %c\n\n", 'A');

	ft_printf("Chaine : %s\n", "Hello, world!");
	printf("Vrai printf -> Chaîne : %s\n\n", "Hello, world!");

	ft_printf("Int : %d\n", -123);
	printf("Vrai printf -> Int : %d\n\n", -123);

	ft_printf("Unsigned int : %u\n", -1000);
	printf("Vrai printf -> Unsigned int : %u\n\n", -1000);

	ft_printf("Hexadecimal minuscule : %x\n", 42);
	printf("Vrai printf -> Hexadecimal minuscule : %x\n\n", 42);

	ft_printf("Hexadecimal majuscule : %X\n", 42);
	printf("Vrai printf -> Hexadecimal majuscule : %X\n\n", 42);

	ft_printf("Adresse de a: %p\n", &a);
	printf("Vrai printf -> Adresse  de a: %p\n\n", &a);

	ft_printf("Pourcentage : %%%%%%\n");
	printf("Vrai printf -> Pourcentage : %%%%%%\n\n");


	ft_printf("%p %p \n", LONG_MIN, LONG_MAX);
	printf("Vrai printf -> %p %p \n\n", (void *)LONG_MIN, (void *)LONG_MAX);


	ft_printf("%p %p \n", -ULONG_MAX, ULONG_MAX);
	printf("Vrai printf -> %p %p \n",(void *)-ULONG_MAX, (void *)ULONG_MAX);

	return (0);
} */
