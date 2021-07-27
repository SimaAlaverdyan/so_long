#include "../include/so_long.h"

int main(int argc, char **argv)
{
    int fd;
    t_utilities util;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        util = start(fd, argv[1]);

        if (border_character_check(util.map.matrix, util.map.height, util.map.width) == 1 &&
            inner_character_check(util.map.matrix, util.map.height, util.map.width) == 1)
        {
        // if (check_norms(util)) {
            util.screen.win = mlx_new_window(util.screen.mlx, util.map.width * util.unitsize, util.map.height * 40, "so long");
            util.screen.img.ptr = mlx_new_image(util.screen.mlx,
                                                util.unitsize * util.map.width, util.unitsize * util.map.height);
            util.screen.img.addr = mlx_get_data_addr(util.screen.img.ptr,
                                                     &util.screen.img.bpp, &util.screen.img.linelen, &util.screen.img.endian);          
            mlx_hook(util.screen.win, 2, 1L << 0, ft_mlx_pressed, &(util.keys));
            mlx_hook(util.screen.win, 3, 1L << 1, ft_mlx_released, &(util.keys));
            mlx_loop_hook(util.screen.mlx, ft_render, &util);        
            mlx_loop(util.screen.mlx);
        }
        else
        {
            printf("noo");
        }
        close(fd);
    }
    return (0);
}