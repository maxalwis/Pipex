/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:31:46 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/24 14:33:38 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		del (tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

/* static void	del(void *content)
{
	if (content)
	{
		free(content);
	}
} */

/* int	main()
{
	t_list *node1 = ft_lstnew(ft_strdup("Bonjour"));
	t_list *node2 = ft_lstnew(ft_strdup("Aurevoir"));

	node1->next = node2;
	node2->next = NULL;

	printf("Avant suppression:\n");
	if (node1 && node1->content)
		printf("%s->", (char *)node1->content);
	if (node2 && node2->content)
		printf("%s\n", (char *)node2->content);

	ft_lstclear(&node2, del);

	printf("Apres suppression :\n");
	if (node2 == NULL)
		printf("La liste a ete correctement supprimee.\n");
	else
		printf("La liste n'a pas ete correctement supprimee.\n");
	return (0);
} */
