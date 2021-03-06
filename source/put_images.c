/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:18:30 by salaverd          #+#    #+#             */
/*   Updated: 2021/07/28 17:18:38 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_render(t_utilities *util)
{
	if (util->state)
	{
		ft_checkinput1(util);
		ft_checkinput2(util);
		ft_checkinput3(util);
		ft_checkinput4(util);
	}
	util->i = 0;
	while (util->i < util->map.height)
	{
		util->j = 0;
		while (util->j < util->map.width)
		{
			ft_mlx_draw_unit(util, util->i, util->j);
			ft_animatefire(util);
			util->j++;
		}
		util->i++;
	}
	mlx_put_image_to_window(util->screen.mlx, util->screen.win, util->screen.img.ptr, 0, 0);
	ft_putmoves(util);
	mlx_do_sync(util->screen.mlx);
	return (0);
}

void	ft_putmoves(t_utilities *util)
{
	char	*num;
	char	*line;

	num = ft_itoa(util->player.steps);
	line = ft_strjoin("Move Count: ", num);
	mlx_string_put(util->screen.mlx, util->screen.win, 5, 5, 0xFFFFFF, line);
	free(line);
	free(num);
}

void	ft_animatefire(t_utilities *util)
{
	if ((double)(clock()) / CLOCKS_PER_SEC - util->time
		>= (double)1 / 10)
	{
		util->frame++;
		util->time = (double)(clock()) / CLOCKS_PER_SEC;
	}
	if (util->frame > 4)
		util->frame = 0;
}