/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:42:03 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/24 13:31:28 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*root;
	t_list	*tmp;

	root = ft_lstnew("Bonjour");
	root->next = ft_lstnew("Les");
	root->next->next = ft_lstnew("Amis");
	ft_lstiter(root, print_content);
	while (root != NULL)
	{
		tmp = root;
		root = root->next;
		free(tmp);
	}
	return (0);
}
