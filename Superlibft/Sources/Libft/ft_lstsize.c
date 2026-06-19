/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:55:46 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

/* int	main()
{
	t_list	node1;
	t_list	node2;
	t_list	node3;
	int		size;

	node1.content = "bonjour";
	node1.next = &node2;

	node2.content = "les";
	node2.next = &node3;

	node3.content = "gens";
	node3.next = NULL;

	size = ft_lstsize(&node1);
	printf("La taille de la liste est de : %d\n", size);
} */
