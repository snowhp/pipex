/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:05:59 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/23 17:05:55 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *f, size_t l)
{
	size_t	i;
	size_t	a;

	if (!*f)
		return ((char *)s);
	if (l == 0)
		return (NULL);
	i = 0;
	while (l > i && s[i] != '\0')
	{
		a = 0;
		while (s[i + a] != 0 && s[i + a] == f[a] && (i + a) < l && f[a] != 0)
		{
			if (f[a + 1] == 0)
				return ((char *)&s[i]);
			a++;
		}
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char *s1 = "oh no not the empty string !";
	char *s2 = "";
	size_t max = ft_strlen(s1);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);
	printf("i1: %s\n", i1);
	printf("i2: %s\n", i2);
	if (i1 == i2)
		printf("\nSucess");
	return (0);
} */
