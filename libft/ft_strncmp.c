/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:53:23 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/05 16:11:16 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n != 0)
	{
		--n;
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (*s1++ == 0)
			break ;
	}
	return (0);
}
/* int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	do {
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (*s1++ == 0)
			break ;
	} while (--n != 0);
	return (0);
} */

/* #include <string.h>
int	main(void)
{
	char s1[] = "es";
	char s2[] = "teste";
	printf("%i\n", ft_strncmp(s1, s2, 4));
	printf("%i\n", strncmp(s1, s2, 4));
	return (0);
} */