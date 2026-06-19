/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:52:34 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len_s;
	char			*result;

	len_s = ft_strlen(s);
	result = malloc(len_s * sizeof(char) + 1);
	if (!s || !f)
		return (NULL);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* char my_func(unsigned int i, char c)
{
	return (c + i);
} */

/* int main(void)
{
	char *s = "abc";
	char *result = ft_strmapi(s, my_func);
	printf("Result: %s\n", result);
	free(result);
	return (0);
} */
