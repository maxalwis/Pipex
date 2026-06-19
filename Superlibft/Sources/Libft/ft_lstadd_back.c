/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:07:31 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/* void print_list(t_list *lst)
{
	while (lst)
	{
		printf("Node at %p, next: %p\n", lst, lst->next);
		lst = lst->next;
	}
}

int main()
{
	t_list *lst;
	t_list *new1;
	t_list *new2;
	t_list *middle;


	middle = malloc(sizeof(t_list));
	if (!middle)
		return (0);
	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	new1 = malloc(sizeof(t_list));
	if (!new1)
		return (0);
	new2 = malloc(sizeof(t_list));
	if (!new2)
		return (0);


	lst->next = middle;
	middle->next = NULL;
	new1->next = NULL;
	new2->next = NULL;


	ft_lstadd_back(&lst, new1);
	printf("After adding new1:\n");
	print_list(lst);

	ft_lstadd_back(&lst, new2);
	printf("After adding new2:\n");
	print_list(lst);

	free(middle);
	free(lst);
	free(new1);
	free(new2);

	return (0);
} */
