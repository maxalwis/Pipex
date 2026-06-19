/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:22:12 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/* static void	del(void *content)
{
	if (content)
	{
		free(content);
	}
} */

/*  int main()
{
	t_list *node1 = ft_lstnew(ft_strdup("Bonjour"));
	t_list *node2 = ft_lstnew(ft_strdup("Aurevoir"));
	t_list *temp;

	node1->next = node2;
	node2->next = NULL;

	printf("Avant suppression:\n");
	printf("%s->%s\n", (char *)node1->content, (char *)node2->content);

	temp = node1;
	node1 = node1->next;
	ft_lstdelone(temp, del);

	printf("Apres suppression du premier element:\n");
	printf("%s->%s\n", (char *)node1->content, (char *)node2->content);

	ft_lstdelone(node1, del);

	return (0);
} */
