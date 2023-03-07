/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:40:15 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/14 17:37:50 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*dst;

	if (nmemb == 0 || size == 0)
		return (ft_calloc (1, 1));
	bytes = nmemb * size;
	dst = malloc(bytes);
	if (!dst)
		return (NULL);
	ft_memset((unsigned char *)dst, 0, bytes);
	return (dst);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	if (memcmp(d1, d2, size * sizeof(int)))
		printf("FAIL");
	else
		printf("SUCESS");
	free(d1);
	free(d2);	
	return (0);
} */
/* 
#include <stdio.h>
int	main(void)
{
	int	*a;
	int	*b;

	a = (int*)ft_calloc(0,sizeof(int));
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	printf("%i %i %i\n", a[0], a[1], a[2]);
	free( a );
	b = (int*)calloc(3, sizeof(int));
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	printf("%i %i %i", b[0], b[1], b[2]);
	free( b );
	return (0);
} */
