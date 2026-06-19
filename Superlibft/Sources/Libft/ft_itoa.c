/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:35:58 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nb_len;
	long	nb;

	nb = n;
	nb_len = ft_countlen(nb);
	str = malloc(sizeof(char) * nb_len + 1);
	if (!str)
		return (NULL);
	str[nb_len] = '\0';
	if (n == 0)
		return (str[0] = '0', str);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		str[--nb_len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/* int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
} */
