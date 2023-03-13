/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putpointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:51:29 by tde-sous          #+#    #+#             */
/*   Updated: 2023/01/20 13:23:01 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_putpointer(unsigned long n)
{
	int	count;

	count = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	count += ft_int_putstr("0x");
	count += ft_int_puthex(n, 'x');
	return (count);
}
