/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:22:48 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/23 16:16:38 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_s1trim(char const *s1, char const *set)
{
	int	i;
	int	a;

	i = 0;
	while (s1[i])
	{	
		a = 0;
		while (set[a])
		{
			if (set[a] == s1[i])
				break ;
			a++;
		}
		if (set[a] != s1[i])
			break ;
		i++;
	}
	return (i);
}

static int	ft_s2trim(char const *s1, char const *set, int e, int i)
{
	int	a;

	while (e > 0 && i < e)
	{	
		a = 0;
		while (set[a])
		{
			if (set[a] == s1[e])
				break ;
			a++;
		}
		if (set[a] != s1[e])
			break ;
		e--;
	}
	return (e);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		e;
	char	*s;

	if (!s1)
		return (NULL);
	i = ft_s1trim(s1, set);
	e = ft_s2trim(s1, set, ft_strlen(s1) - 1, i);
	s = (char *)malloc((e - i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1 + i, e - i + 2);
	return (s);
}

/* #include <stdio.h>
int	main()
{
	char *s1;
	char *set;
	s1 = "  \t \t \n   \n\n\n\t";
	set = " \n\t";
	printf("%s", ft_strtrim(s1,set));
	return (0);
} */