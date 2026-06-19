/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:54:41 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t				i;
	const unsigned char	*s1;

	s1 = (const unsigned char *)s;
	i = 0;
	while (i < len)
	{
		if (s1[i] == (unsigned char)c)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}

/* int	main()
{
	char str[] = "bonjour les amis";
	int c = 'b';
	char *res = ft_memchr(str, c, sizeof(str));

	if (res)
		printf("Character '%c' found at position %ld.\n", c, res - str);
	else
		printf("Character '%c' not found in the %zu bytes.\n", c, sizeof(str));
} */
