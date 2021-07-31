/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:18:44 by salaverd          #+#    #+#             */
/*   Updated: 2021/07/28 17:18:46 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    ft_triggervictory(t_utilities *res)
{
    res->screen.victor = mlx_new_window(res->screen.mlx, res->twin.width,
			res->twin.height, "you were too good!");
	mlx_hook(res->screen.victor, 2, 1L << 0, ft_mlx_pressed, &res->keys);
	mlx_put_image_to_window(res->screen.mlx, res->screen.victor,
		res->twin.ptr, 0, 0);
	res->state = 0;

}

void    ft_triggerloss(t_utilities *res)
{
    res->screen.lose = mlx_new_window(res->screen.mlx, res->tlose.width,
			res->tlose.height, "you lost!!O");
	mlx_hook(res->screen.lose, 2, 1L << 0, ft_mlx_pressed, &res->keys);
	mlx_put_image_to_window(res->screen.mlx, res->screen.lose,
		res->tlose.ptr, 0, 0);
	res->state = 0;
}