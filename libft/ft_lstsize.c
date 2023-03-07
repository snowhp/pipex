/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:09:40 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/21 18:46:24 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst)
	{
		while (lst != NULL)
		{
			count++;
			lst = lst->next;
		}
	}
	return (count);
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	t_list *l;
	int actual;
	int expected;

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("3"));
	expected = 3;
	printf("%i\n", actual = ft_lstsize(l));
	if (actual == expected)
	{	
		printf("Sucess");
		return 0;
	}
	printf("FAIL");
} */