/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:17:34 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/09 12:21:58 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

/* #include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char *str = "the cake is a lie asdasd!\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";

	printf("%zu\n", ft_strlcat(buff2, str, max));
	printf("%s\n", buff2);

	printf("%zu\n", strlcat(buff1, str, max));
	printf("%s\n", buff1);
	return (0);
} */

/* size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t srclen = ft_strlen(src);
	const size_t dstlen = ft_strnlen(dst, size);
	if (dstlen == size) 
		return (size + srclen);
	if (srclen < size - dstlen)
		ft_memcpy(dst + dstlen, src, srclen);
	else
	{
		ft_memcpy(dst + dstlen, src, size - 1);
		dst[dstlen + size - 1] = '\0';
	}
	return (dstlen + srclen);
} */
