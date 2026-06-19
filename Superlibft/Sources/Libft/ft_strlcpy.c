/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:25:20 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*int	main(int ac, char *av[])
{

	char dest[10];
	memset(dest, 'A', 10);

	if (ac == 3)
	{
		printf("%zu\n", ft_strlcpy(dest, av[1], atoi(av[2])));
		printf("%zu\n", ft_strlen(dest));
		printf("%s\n", dest);

		printf("%zu\n", strlcpy(dest, av[1], atoi(av[2])));
		printf("%s\n", dest);
		printf("%zu\n", ft_strlen(dest));

	}
}*/
