/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:17:45 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/07 18:03:44 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	const char s[] = "";
	printf("%s\n", ft_strchr(s,'a'));
	const char d[] = "";
	printf("%s\n", strchr(d,'a'));
	return (0);
} */