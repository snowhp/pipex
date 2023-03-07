/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:46:59 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/18 18:55:07 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (!s || !f)
		return (NULL);
	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* static char ft_upup(unsigned int i, char c)
{
	(void) i;

	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

#include <stdio.h>
int	main(void)
{
	char s1[] = "teste as AAA \0";
	printf("%s\n", s1);
	printf("%s", ft_strmapi(s1, ft_upup));
	
	return (0);
} */