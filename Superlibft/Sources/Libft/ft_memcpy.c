/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:47:57 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sc = src;

	dst = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	i = 0;
	if (!dst && !sc)
		return (NULL);
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dest);
}
/* int main()
{
	const char src[50] = "Ciao les noobs";
	char dest[50];

	ft_memcpy(dest, src , (ft_strlen(src) + 1));
	printf("%s", dest);
} */
