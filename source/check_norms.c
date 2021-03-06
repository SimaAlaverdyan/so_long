/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:16:30 by salaverd          #+#    #+#             */
/*   Updated: 2021/07/28 17:16:51 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int     exit_count(t_utilities util)
{
    int count;
    int i;
    int j;

    i = 0;
    count = 0;

    while (i < util.map.height)
    {
        j = 0;
        while (j < util.map.width)
        {
            if (util.map.matrix[i][j] == 'E')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int     player_count(t_utilities util)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;

    while (i < util.map.height)
    {
        j = 0;
        while (j < util.map.width)
        {
            if (util.map.matrix[i][j] == 'P')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int     ft_check_extension(char *path, char *ext)
{
	int	pathlen;
	int	extlen;

	pathlen = ft_strlen(path);
	extlen = ft_strlen(ext);
	if (!(extlen == 4) || !(pathlen > 4))
		return (0);
	return (*(path + pathlen - 1) == *(ext + extlen - 1)
		&& *(path + pathlen - 2) == *(ext + extlen - 2)
		&& *(path + pathlen - 3) == *(ext + extlen - 3)
		&& *(path + pathlen - 4) == *(ext + extlen - 4));
}

int     check_norms(t_utilities util)
{
    int exitCount;
    int playerCount;

    exitCount = exit_count(util);
    playerCount = player_count(util);

    if (border_character_check(util.map.matrix, util.map.height, util.map.width) == 0)
    {
        ft_exit("The map must be closed/surrounded by walls");
    }
    else if (inner_character_check(util.map.matrix, util.map.height, util.map.width) == 0)
    {
        ft_exit("The map must have only '1' '0' 'P' 'C' 'E' 'F' characters");
    }
    else if (util.player.goal == 0)
    {
        ft_exit("There is no food in this map");
    }
    else if (playerCount == 0)
    {
        ft_exit("The map must have start position");
    }
    else if (exitCount == 0)
    {
        ft_exit("The map must have exit");
    }
    return (1);
}
