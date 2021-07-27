/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:17:41 by salaverd          #+#    #+#             */
/*   Updated: 2021/01/30 12:30:25 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(new, s, len);
	*(new + len) = '\0';
	return (new);
}
