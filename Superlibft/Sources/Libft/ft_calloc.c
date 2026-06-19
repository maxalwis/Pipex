/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:16:46 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	total;
	void	*ptr;

	if (size != 0 && number > SIZE_MAX / size)
		return (NULL);
	total = number * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}

/* int main()
{
	int i = 0;
	int n = 1;
	int *array;

	array = (int *)ft_calloc(n, sizeof(int));
	if (!array)
		return (1);
	printf("Tableau apres calloc: ");
	while (i < n)
		printf("%d ", array[i++]);
	printf("\n");
	free(array);
	return (0);
} */
