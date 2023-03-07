/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:37:29 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/23 15:48:41 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&head, ft_lstnew((*f)(lst->content)));
		lst = lst->next;
	}
	return (head);
}
