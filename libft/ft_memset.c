/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:14:28 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/04 20:37:21 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*s;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = (char)c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	void str[] = "TESTE";
	printf("%s", memset(str, '$', 2));
	printf("%s", ft_memset(str, '$', 2));
}*/
