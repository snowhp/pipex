/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:10:58 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/14 19:06:16 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;
	char	*dst;

	src = (char *) s;
	dst = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, ft_strlen(s) + 1);
	return (dst);
}
/* #include <string.h>
#include <stdio.h>
int	main(void)
{
	char *teste;
	char dup[] = "I malloc so I am.";
	teste = ft_strdup(dup);
	printf("%s\n", teste);
	char *teste1;
	char dup1[] = "I malloc so I am.";
	teste1 = strdup(dup1);
	printf("%s\n", teste1);
	return (0);
} */