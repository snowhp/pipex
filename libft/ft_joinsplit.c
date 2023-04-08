/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:16:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/08 18:59:31 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function receives a string and a int that represents the way of return
	ctrl = 0  - Returns the 0 if its last. Used in the beginning of the str
	ctrl != 0 - Returns number of chars. Used for end of str
*/
int	ft_isquotes(char *str, int ctrl)
{
	if (str[0] == '\"' && str[1] == '\'')
	{
		if (str[2] == '\0' && !ctrl)
			return (0);
		return (2);
	}
	else if (str[0] == '\'' && str[1] == '\"')
	{
		if (str[2] == '\0' && !ctrl)
			return (0);
		return (2);
	}
	else if (str[0] == '\"' || str[0] == '\'')
	{
		if (str[1] == '\0' && !ctrl)
			return (0);
		return (1);
	}	
	else
		return (0);
}

/* Count numbers of words separated by 'c'.*/
void	ft_wcount(char *str, char c, int *wcount)
{
	int	i;
	int	ctrl;
	int	ctrl1;

	ctrl = 0;
	ctrl1 = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ctrl1 && ft_isquotes((str + i), 0))
		{
			ctrl1 = 1;
			(*wcount)++;
		}
		else if (ctrl1 && ft_isquotes((str + i), 0))
			ctrl1 = 0;
		if (!ctrl && !ctrl1 && !ft_isquotes((str + i), 0))
		{
			ctrl = 1;
			(*wcount)++;
		}
		else if (ctrl && str[i] == c)
			ctrl = 0;
		i += ft_isquotes((str + i), 0) + 1;
	}
}

int	ft_checkchar(char *str, char c)
{
	int		ctrl;
	int		l;
	int		extra;

	l = 0;
	ctrl = 0;
	extra = 0;
	while (str[l])
	{
		if (str[l] == c && !ctrl)
			break ;
		if (ft_isquotes((str + l), 1) && ctrl)
			break ;
		if (ft_isquotes((str + l), 0) && !ctrl)
		{
			ctrl = 1;
			extra += ft_isquotes((str + l), 0);
			if (extra == 2)
				l++;
		}
		l++;
	}
	return (l - extra);
}

static char	*ft_word(char *str, char c)
{
	int		l;
	int		i;
	char	*res;

	l = ft_checkchar(str, c);
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	i = ft_isquotes(str, 1);
	while (i-- > 0)
		*str++;
	i = 0;
	while (i < l)
		res[i++] = *str++;
	return (res);
}

/* This function will split a string by give char c, but joining whats inside 
cj, if its a even number otherwise return 0*/
char	**ft_joinsplit(char *s, char c, char cj)
{
	int		wcount;
	int		i;
	char	**result;

	wcount = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	ft_wcount(s, c, &wcount);
	if ((ft_countchar(s, cj) % 2) != 0)
		return (0);
	result = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < wcount)
	{
		while (*s == c)
			s++;
		result[i] = ft_word(s, c);
		s += ft_strlen(result[i++]);
	}
	return (result);
}

/* int	main()
{
	char	c;
	char	cj;

	char *s3 = "awk \'{count++} END {print count}\'";
	c = ' ';
	cj = 39;

	char **arr = ft_joinsplit(s3, c, cj);
	int i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);
		free(arr[i]);  
		i++;
	}
	free(arr);
	char *s1 = "awk \"{count++} END {print count}\"";
	char *s2 = "awk \'\"{count++} END {print count}\"\'";
	char *s = "awk \"\'{count++} END {print count}'\"";
	arr = ft_joinsplit(s1, c, cj);
	i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]); 
		free(arr[i]);     
		i++;
	}
	free(arr);
	arr = ft_joinsplit(s2, c, cj);
	i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);     
		free(arr[i]); 
		i++;
	}
	free(arr);
	arr = ft_joinsplit(s, c, cj);
	i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);      
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
} */
