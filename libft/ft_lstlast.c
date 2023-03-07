/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:46:52 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/21 19:02:41 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	t_list *l;
	t_list *expected;
	t_list *actual;

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("3"));
	printf("%p\n", expected = l->next->next);
	printf("%p\n", actual = ft_lstlast(l));
	if (actual == expected)
	{	
		printf("Sucess");
		return (0);
	}
	printf("Fail");

} */