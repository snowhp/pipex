/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:09:03 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/03 15:16:10 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	char c = 'x';
	printf("%i\n", isascii(c));
	printf("%i", ft_isascii(c));
	return (0);		
}*/