/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:01:23 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/03 14:18:42 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}
/*#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	char c = '4';
	printf("%i\n", isalpha(c));
	printf("%i", ft_isalpha(c));
	return (0);		
}*/
