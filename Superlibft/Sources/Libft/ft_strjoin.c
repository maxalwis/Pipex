/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:40:38 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/24 18:02:25 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(len * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
} */

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

/* int	main()
{
	char s1[] = "salut";
	char s2[] = "la team";

	printf("%s", ft_strjoin(s1, s2));
} */
