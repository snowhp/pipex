/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:59:12 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/24 13:09:17 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (n != 0)
	{
		p1 = s1;
		p2 = s2;
		while (n != 0)
		{
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
			n--;
		}
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>
int	main(void)
{
	char str1[] = "aa!";
   	char str2[] = "a";
	printf("%i\n", ft_memcmp(str1, str2, 3));
	printf("%i\n", memcmp(str1, str2, 3));
	return (0);
} */