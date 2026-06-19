/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:33:14 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)str);
	while (i < n && str[i])
	{
		j = 0;
		while (i + j < n && str[i + j] == needle[j] && str[i + j] && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
/*int	main()
{
	const char	a[]= "bonjour tout le monde";
	const char	b[]= "\0";
	const char	a1[]= "bonjour tout le monde";
	const char	b1[]= "\0";

	printf("%s\n", ft_strnstr(a, b, 10));
	printf("%s\n", strnstr(a1, b1, 10));
} */
