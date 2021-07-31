/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:18:23 by salaverd          #+#    #+#             */
/*   Updated: 2021/07/28 17:18:25 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_mlx_pixel_put(t_screen *data, int x, int y, int color)
{
	char *dst;

	dst = data->img.addr + (y * data->img.linelen + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_mlx_get_color(t_img *imgstruct, int x, int y)
{
	char *dst;

	dst = imgstruct->addr + (y * imgstruct->linelen + x * (imgstruct->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_mlx_draw_unit(t_utilities *util, int i, int j)
{
	util->x = 0;
	while (util->x < util->unitsize)
	{
		util->y = 0;
		while (util->y < util->unitsize)
		{
			if (util->player.x == util->exit.x && util->player.y == util->exit.y && i == util->player.x && j == util->player.y)
				util->sprite = util->texit;
			else
				util->sprite = util->tfloor;
			ft_putspritepixel(util, i, j);
			ft_selectsprite(util, i, j);
			ft_putspritepixel(util, i, j);
			util->y++;
		}
		util->x++;
	}
}

void	ft_selectsprite(t_utilities *util, int i, int j)
{
	if (util->map.matrix[i][j] == '1')
		util->sprite = util->twall;
	else if (util->map.matrix[i][j] == 'C')
		util->sprite = util->tfood;
	else if (util->map.matrix[i][j] == 'P')
		util->sprite = util->tplayer;
	else if (util->map.matrix[i][j] == 'E')
		util->sprite = util->texit;
	else if (util->map.matrix[i][j] == 'F')
		util->sprite = util->tenemy[util->frame];
}

void	ft_putspritepixel(t_utilities *util, int i, int j)
{
	util->texx = (int)((float)util->y / util->unitsize * util->sprite.width);
	util->texy = (int)((float)util->x / util->unitsize * util->sprite.height);

	if (ft_mlx_get_color(&util->sprite, util->texx, util->texy) != 0xFF000000)
		ft_mlx_pixel_put(&util->screen, j * util->unitsize + util->y,
						 i * util->unitsize + util->x, ft_mlx_get_color(&util->sprite, util->texx, util->texy));
}
