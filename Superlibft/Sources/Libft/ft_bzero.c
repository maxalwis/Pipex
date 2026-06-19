/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:47:49 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

/* int main(void)
{
	char str[] = "bonjour tout le monde";
	int n = 2;
	int i = 0;
	int len = ft_strlen(str);

	printf("Avant ft_bzero: %s\n", str);
	ft_bzero(str, n);
	printf("Après ft_bzero : %s\n", str);
	while (i < len)
	{
		if (str[i] == '\0')
			printf("\\0");
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\n");

	return (0);
} */
