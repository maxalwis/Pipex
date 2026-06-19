/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:08 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
/*int	main()
{
	char c[]= "hello world";
	char *d;

	d = ft_strchr(c, 'w');
	printf("%c", *d);
}*/

/* int main()
{
	const char str[] = "Hello, World!";
	char *result;

	result = ft_strchr(str, 'o');
	if (result)
		printf("First 'o' at position %ld: %c\n", result - str, *result);
	else
		printf("Character not found\n");
} */
