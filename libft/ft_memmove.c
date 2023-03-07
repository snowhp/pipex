/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:58:58 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/23 15:55:37 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest0;
	char const	*source0;

	dest0 = dst;
	source0 = src;
	if (source0 < dest0)
	{
		source0 += len;
		dest0 += len;
		while (len)
		{
			*--dest0 = *--source0;
			--len;
		}
	}
	else if (source0 != dest0)
	{
		while (len)
		{
			*dest0++ = *source0++;
			--len;
		}
	}
	return (dst);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char dest[] = "teste";
	char src[] = "olaaaa";
	ft_memmove(&dest, &src, 4);
	printf("%s\n", dest);
	char dest1[] = "teste";
	ft_memmove(&dest1, &src, 4);
	printf("%s", dest1);
	return (0);
} */