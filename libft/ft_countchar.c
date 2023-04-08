/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:34:59 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/06 19:59:10 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* This function takes a string (str), and a char c. 
	Returning the numbers of times Char c is contained in str.*/
int	ft_countchar(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
