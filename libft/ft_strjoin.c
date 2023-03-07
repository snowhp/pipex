/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:14:14 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/18 16:55:54 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		size;
	int		i;

	if (!s1)
		return (NULL);
	i = -1;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(size * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	i = -1;
	while (s2[++i])
		dst[i + ft_strlen(s1)] = s2[i];
	dst[i + ft_strlen(s1)] = '\0';
	return (dst);
}

/* #include <stdio.h>
int	main()
{
	char *s1;
	char *s2;

	s1 = "";
	s2 = "asd";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
} */