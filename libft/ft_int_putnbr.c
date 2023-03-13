/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:04:08 by tde-sous          #+#    #+#             */
/*   Updated: 2023/01/18 15:50:53 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_putnbr(long n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_int_putstr("-2147483648");
	}
	else if (n < 0)
	{
		n = -n;
		count += ft_int_putchar('-');
		count += ft_int_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_int_putnbr((n / 10));
		count += ft_int_putnbr(n % 10);
	}
	else
	{
		count += ft_int_putchar((n + '0'));
	}
	return (count);
}
