/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:30:54 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != 0 && new != 0)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* int	main()
{
	t_list	*lst;
	t_list	*new;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (1);
	new = malloc(sizeof(t_list));
	if (!new)
		return (1);
	printf("lst : %p\n", lst);
	printf("new : %p\n", new);
	ft_lstadd_front(&lst, new);
	printf("lst : %p\n", lst);
	printf("new : %p\n", new);
	printf("next : %p\n", new->next);
	free(lst);
} */
