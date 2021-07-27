/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:35:20 by salaverd          #+#    #+#             */
/*   Updated: 2021/01/30 12:11:54 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = 0;
	while (!diff && s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		diff = s1[i] - s2[i];
		i++;
	}
	if (diff == 0)
	{
		if (ft_strlen(s1) > ft_strlen(s2) && ft_strlen(s2) < n)
			return (1);
		else if (ft_strlen(s1) < ft_strlen(s2) && ft_strlen(s1) < n)
			return (-1);
	}
	return (diff);
}
