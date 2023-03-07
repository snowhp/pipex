/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:26:05 by tde-sous          #+#    #+#             */
/*   Updated: 2022/11/26 14:38:11 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset((void *) s, 0, (size_t) n);
}

/*#include <stdio.h>
#include <strings.h>
int	main(void)
{
	char str[] = "teste";
	char str1[] = "teste";
	ft_bzero(&str, 10);
	printf("|%s|\n", str);
	bzero(&str1, 10);
	printf("|%s|\n", str1);
}*/
