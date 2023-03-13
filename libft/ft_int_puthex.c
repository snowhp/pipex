/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_puthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:57:01 by tde-sous          #+#    #+#             */
/*   Updated: 2023/01/20 13:23:14 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_puthex(unsigned long n, char c)
{
	int		count;
	char	*hex;

	count = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_int_puthex((n / 16), c);
		count += ft_int_puthex((n % 16), c);
	}
	else
		count += ft_int_putchar(*(hex + n));
	return (count);
}
