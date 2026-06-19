/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:59:39 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/24 13:31:58 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int	main()
{
	t_list	node1;
	t_list	node2;
	t_list	node3;

	node1.content = "bonjour";
	node1.next = &node2;

	node2.content = "les";
	node2.next = &node3;

	node3.content = "amis";
	node3.next = NULL;

	printf("node1 content: %s\n", (char *)node1.content);
	printf("node2 content: %s\n", (char *)node2.content);
	printf("node3 content: %s\n", (char *)node3.content);

	printf("%s\n", (char *)ft_lstlast(&node1)->content);
} */
