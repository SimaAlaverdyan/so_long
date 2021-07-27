/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:31:29 by salaverd          #+#    #+#             */
/*   Updated: 2021/01/30 12:08:35 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t a;
	size_t b;
	size_t c;

	a = 0;
	while (dest[a] != '\0')
		++a;
	c = 0;
	while (src[c] != '\0')
		++c;
	if (size <= a)
		c += size;
	else
		c += a;
	b = 0;
	while (src[b] != '\0' && a + 1 < size)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (c);
}
