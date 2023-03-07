/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:50:28 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/24 00:27:40 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(const char *str, char c)
{
	int	i;
	int	count;
	int	registc;

	count = 0;
	registc = 1;
	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] != c && registc)
		{
			count++;
			registc = 0;
		}
		else if (registc == 0 && str[i] == c)
			registc = 1;
		i++;
	}
	return (count);
}

static char	*ft_word(const char *str, char c)
{
	int		l;
	int		i;
	char	*res;

	l = 0;
	while (str[l] != '\0' && str[l] != c)
		l++;
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	i = 0;
	while (i < l)
		res[i++] = *str++;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		wcount;
	int		i;
	char	**result;

	wcount = ft_wcount(s, c);
	result = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < wcount)
	{
		while (*s != '\0' && *s == c)
			s++;
		result[i] = ft_word(s, c);
		s += ft_strlen(result[i++]);
	}
	result[i] = NULL;
	return (result);
}

/* #include <stdio.h>
int	main()
{
	char	*s;
	char	c;
	
	s = "\0aa\0bbb";
	c = '\0' ;

	char **arr = ft_split(s, c);
	int i = 0;
	while (arr[i] != 0)
	{
		printf("[%s]\n", arr[i]);      
		i++;
	}
	return (0);
} */
