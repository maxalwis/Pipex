/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:22:01 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*sc;
	size_t				i;

	dst = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	i = 0;
	if (!dst && !sc)
		return (NULL);
	if (dst < sc)
	{
		while (i < n)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dst[n] = sc[n];
	}
	return (dest);
}

/* int	main(void)
{
	char dest_str[] = "Ancienne chaine";
	const char src_str[]  = "Nouvelle chaine";
	printf("Before memmove dest = %s, src = %s\n", dest_str, src_str);
	ft_memmove(dest_str, src_str, 2);
	printf("After memmove dest = %s, src = %s\n", dest_str, src_str);
} */
