/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:32:56 by tde-sous          #+#    #+#             */
/*   Updated: 2023/01/24 11:56:49 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *str, va_list ap)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_int_putchar(va_arg(ap, int));
	else if (*str == 's')
		count += ft_int_putstr(va_arg(ap, char *));
	else if (*str == 'p')
		count += ft_int_putpointer(va_arg(ap, unsigned long));
	else if (*str == 'd' || *str == 'i')
		count += ft_int_putnbr(va_arg(ap, int));
	else if (*str == 'u')
		count += ft_int_putnbr(va_arg(ap, unsigned int));
	else if (*str == 'x' || *str == 'X')
		count += ft_int_puthex(va_arg(ap, unsigned int), *str);
	else if (*str == '%')
		count += ft_int_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*(str) == '%')
		{
			count += ft_check((str + 1), ap);
			str++;
		}
		else
			count += ft_int_putchar(*str);
		str++;
	}
	va_end(ap);
	return (count);
}
