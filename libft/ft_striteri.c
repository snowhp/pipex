/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:49:33 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/18 16:56:22 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* static void ft_upup(unsigned int i, char* c)
{
	i = 0;

	if (c[i] >= 'a' && c[i] <= 'z')
		c[i] -= 32;
}

#include <stdio.h>
int	main(void)
{
	char s1[] = "teste as AAA \0";
	printf("%s\n", s1);
	ft_striteri(s1, ft_upup);
	printf("%s", s1);
	return (0);
} */