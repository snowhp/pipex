/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:46:14 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/04 20:37:56 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*big;

	big = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (big[i] == c)
			return ((void *)&big[i]);
		i++;
	}
	return (NULL);
}

/*TESTAR
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*big;

	big = (const char *)s;
	while (n-- > 0)
	{
		if (*big++ == c)
			return ((void *)&big);
		i++;
	}
	return (NULL);
}*/

/* #include <string.h>
int	main(void)
{
	const char str[] = "http://www.tutorialspointa.com";
   	const char ch = 'a';
	char *result = (char *) ft_memchr(str, ch, strlen(str));
	printf("%s\n", result);
	const char str1[] = "http://www.tutorialspointa.com";
	result = (char *) memchr(str1, ch, strlen(str));
	printf("%s\n", result);
	return (0);
} */