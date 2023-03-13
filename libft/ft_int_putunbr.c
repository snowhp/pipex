/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putunbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:44:54 by tde-sous          #+#    #+#             */
/*   Updated: 2023/01/18 17:45:56 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
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
