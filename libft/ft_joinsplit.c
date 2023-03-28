/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:16:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/28 15:38:33 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Count numbers of words separated by 'c'.*/
void	ft_wcount(const char *str, char c, char cj, int *wcount)
{
	int	i;
	int	ctrl;
	int	ctrl1;

	ctrl = 0;
	ctrl1 = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ctrl1 && str[i] == cj)
		{
			ctrl1 = 1;
			(*wcount)++;
		}
		else if (ctrl1 && str[i] == cj)
			ctrl1 = 0;
		if (!ctrl && !ctrl1 && str[i] != c && str[i] != cj)
		{
			ctrl = 1;
			(*wcount)++;
		}
		else if (ctrl && str[i] == c)
			ctrl = 0;
		i++;
	}
}

int	ft_checkchar(const char *str, char c)
{
	int		ctrl;
	int		l;

	l = 0;
	ctrl = 0;
	while (str[l] != '\0' && str[l] != c)
	{
		if (str[l] == 39 && !ctrl)
		{
			ctrl = 1;
			c = '\'';
		}
		l++;
	}
	if (c == '\'')
		l++;
	return (l);
}

static char	*ft_word(const char *str, char c)
{
	int		l;
	int		i;
	char	*res;

	l = ft_checkchar(str, c);
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	i = 0;
	while (i < l)
		res[i++] = *str++;
	return (res);
}

/* This function will split a string by give char c, but joining whats inside 
cj, if its a even number otherwise return 0*/
char	**ft_joinsplit(char const *s, char c, char cj)
{
	int		wcount;
	int		i;
	char	**result;

	wcount = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	ft_wcount(s, c, cj, &wcount);
	if ((ft_countchars(s, cj) % 2) != 0)
		return (0);
	result = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < wcount)
	{
		while (*s == c)
			s++;
		if (*s == cj)
			result[i] = ft_word(s, c);
		else
			result[i] = ft_word(s, c);
		s += ft_strlen(result[i++]);
	}
	return (result);
}

/* #include <stdio.h>
int	main()
{
	char	*s;
	char	c;
	char	cj;

	s = "awk '{count++} END {print count}'";
	c = ' ';
	cj = 39;

	char **arr = ft_joinsplit(s, c, cj);
	int i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);      
		i++;
	}
	return (0);
}
 */