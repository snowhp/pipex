/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:16:39 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/04 21:40:33 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}

/* #include <ctype.h>
#include <stdio.h>
int	main(void)
{
	char c = '~';
	printf("%i\n", isprint(c));
	printf("%i\n", ft_isprint(c));
	return (0);		
} */
