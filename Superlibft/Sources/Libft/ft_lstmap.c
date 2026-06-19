/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:56:10 by maalwis           #+#    #+#             */
/*   Updated: 2025/02/27 13:02:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst)
		return (0);
	new_list = NULL;
	while (lst)
	{
		if (f)
			new_node = ft_lstnew(f(lst ->content));
		else
			new_node = ft_lstnew(lst ->content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst ->next;
	}
	return (new_list);
}

/* static void	delete(void *content)
{
	if (content)
	{
		free(content);
	}
}

void	*to_uppercase(void *content)
{
	char	*str = (char *)content;
	char	*new_str = ft_strdup(str);
	int		i;

	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i])
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] -= 32;
		i++;
	}
	return (new_str);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

int	main(void)
{
	t_list *root = ft_lstnew(ft_strdup("Bonjour"));
	t_list *node2 = ft_lstnew(ft_strdup("les"));
	t_list *node3 = ft_lstnew(ft_strdup("amis"));
	t_list *new_list;
	t_list *tmp;

	root->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("Liste originale:\n");
	print_list(root);

	new_list = ft_lstmap(root, to_uppercase, delete);

	printf("\nListe transformee:\n");
	print_list(new_list);

	while (root != NULL)
	{
		tmp = root->next;
		ft_lstdelone(root, delete);
		root = tmp;
	}
	while (new_list != NULL)
	{
		tmp = new_list->next;
		ft_lstdelone(new_list, delete);
		new_list = tmp;
	}

	return (0);
} */
