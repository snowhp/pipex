/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:48:22 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/07 16:22:57 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destaddr;
	const char	*srcaddr;

	if (!dest && !src)
		return (0);
	destaddr = (char *)dest;
	srcaddr = (char *)src;
	while (n-- > 0)
		*destaddr++ = *srcaddr++;
	return (dest);
}

/* int	main(void)
{
	char dest[] = "OLAaa";
	char src[] = "";
	ft_memcpy(&dest, &src, 2);
	printf("%s\n", dest);
	char dest1[] = "OLAaa";
	char src1[] = "";
	ft_memcpy(&dest1, &src1, 2);
	printf("%s\n", dest1);
	return (0);
} */
