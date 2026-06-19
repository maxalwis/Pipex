/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:41 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	s11;
	unsigned char	s22;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		s11 = (unsigned char)s1[i];
		s22 = (unsigned char)s2[i];
		if (s11 != s22 || s11 == '\0' || s22 == '\0')
			return (s11 - s22);
		i++;
	}
	return (0);
}

/* int	main()
{
	char	c[] = "hello";
	char	d[] = "baa";
	
	printf("%d", ft_strncmp(c, d, 1));
	printf("\n%d", strncmp(c, d, 1));
} */
