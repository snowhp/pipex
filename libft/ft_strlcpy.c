/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:42:51 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/14 18:58:55 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const size_t	srclen = ft_strlen(src);

	if (srclen + 1 < size)
		ft_memcpy(dest, src, srclen + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}
/* 
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t    i;
	
	i = 0;
	if (size >= ft_strlen(src))
	{
	    while (i < size-1)
	    {
	        dest[i] = src[i];
	        i++;
	    }
	}
	dest[i] = '\0';
	return (ft_strlen(src));
} */

/* #include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char dest[] = "t";
	char src[] = "ola";
	ft_strlcpy(dest, src, 0);
	printf("FT> %s\n", dest);
	char dest1[] = "t";
	strlcpy(dest1, src, 0);
	printf("> %s", dest1);
	return (0);
}  */