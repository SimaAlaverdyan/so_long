/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:17:53 by salaverd          #+#    #+#             */
/*   Updated: 2021/07/28 17:17:55 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int    destroy_hook(int keycode, t_utilities *util)
{
    (void)keycode;
    (void)util;
    exit(0);

    return (0);
}

int     main(int argc, char **argv)
{
    int fd;
    t_utilities util;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        util = start(fd, argv[1]);

        if (!(ft_check_extension(argv[1], ".ber")))
		    ft_exit("Invalid file format.");
        if (check_norms(util)) {
            util.screen.win = mlx_new_window(util.screen.mlx, util.map.width * util.unitsize, util.map.height * util.unitsize, "so long");
            util.screen.img.ptr = mlx_new_image(util.screen.mlx,
                util.unitsize * util.map.width, util.unitsize * util.map.height);
            util.screen.img.addr = mlx_get_data_addr(util.screen.img.ptr,
                &util.screen.img.bpp, &util.screen.img.linelen, &util.screen.img.endian);          
            mlx_hook(util.screen.win, 2, 1L << 0, ft_mlx_pressed, &(util.keys));
            mlx_hook(util.screen.win, 3, 1L << 1, ft_mlx_released, &(util.keys));
            mlx_loop_hook(util.screen.mlx, ft_render, &util);      
            mlx_string_put( util.screen.mlx,  util.screen.win,  0, 0 ,  0xFFFFFF,  ft_itoa(util.player.steps));
            mlx_hook(util.screen.win, 17, 1L << 17, destroy_hook, &util);
            mlx_loop(util.screen.mlx);
        }
        close(fd);
    }
    else
        ft_exit("Plese input the map");
    
    return (0);
}
