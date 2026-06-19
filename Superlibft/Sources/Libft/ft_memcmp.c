/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:39:00 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11;
	const unsigned char	*s22;

	s11 = (const unsigned char *)s1;
	s22 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	a[]= "bonjour";
	char	b[]= "bonjour t";

	printf("%d\n", ft_memcmp(a, b, 10));
	printf("%d\n", memcmp(a, b, 10));
}*/