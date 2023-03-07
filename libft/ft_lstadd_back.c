/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:04:58 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/23 15:48:07 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*(lst));
			tmp->next = new;
		}
	}
}

/* #include <string.h>
#include <stdio.h>
int	main()
{
	t_list *l = ft_lstnew(strdup("nyacat"));
	t_list *n = ft_lstnew(strdup("OK"));

	ft_lstadd_back(&l, n);
	if (l->next == n && !strcmp(l->next->content, "OK"))
	{
		printf("SUCESS");
	}
	else
		printf("Failed");
	return (0);
} */