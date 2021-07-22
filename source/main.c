#include "../include/so_long.h"

// int main(int argc, char **argv)
// {
// 	char **matrix;
// 	int fd;
// 	int rows;
// 	int cols;
// 	Struct result;

// 	// void *mlx;
// 	// void *mlx_win;
// 	// void *img;
// 	// char *path;
// 	// int img_width = 30;
// 	// int img_height = 30;

// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		result = matrix_row_col(fd);

// 		rows = result.rows;
// 		cols = result.cols;
// 		matrix = create_matrix(argv[1], fd, rows, cols);

// 		if (border_character_check(matrix, rows, cols) == 1
// 			&& inner_character_check(matrix, rows, cols) == 1)
// 		{
// 			printf("yaaaasss");
// 		}
// 		else
// 		{
// 			printf("noo");
// 		}
// 		close(fd);
// 		// mlx = mlx_init();
// 		// mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 		// path = "../img/wall.xpm";

// 		// img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
// 		// mlx_put_image_to_window(mlx, mlx_win, img, 30, 40);
// 	}
// 	return (0);
// }
// #include <mlx.h>
// #include <stdio.h>

// int main(void)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	void *img1;
// 	void *img2;
// 	char *path1;
// 	char *path2;
// 	int img_width = 30;
// 	int img_height = 30;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 	path1 = "img/street.xpm";
// 	path2 = "img/jump.xpm";

// 	// for (size_t i = 0; i < 4; i++)
// 	// {
// 		// img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
// 		// img = mlx_new_image(mlx, 200, 200);
// 		img1 = mlx_xpm_file_to_image(mlx, path1, &img_width, &img_height);
// 		mlx_put_image_to_window(mlx, mlx_win, img1, 30, 40);

// 		img2 = mlx_xpm_file_to_image(mlx, path2, &img_width, &img_height);
// 		mlx_put_image_to_window(mlx, mlx_win, img2, 60, 100);
// 	// }

// 	mlx_loop(mlx);
// }

int wall_to_window(char **matrix, int row, int col)
{
    t_screen vars;
    // int     bpp;
    // int     size_line;
    // int     endian;

    char *wall;
    char *player;
    char *burger;
    char *door;
    // void    *img;
    vars.mlx = mlx_init();
    vars.win = mlx_new_image(vars.mlx, 1000, 600);
    void *img_ptr;

    int img_width;
    int img_height;
    wall = "img/wall.xpm";
    player = "img/jump.xpm";
    burger = "img/burger.xpm";
    door = "img/exit.xpm";
    vars.win = mlx_new_window(vars.mlx, col * 40, row * 40, "Hello world!");
    
    int k = 0;
    int y = 0;
    for (int i = 0; i < row; i++)
    {
        k = 0;
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '1')
            {
                img_ptr = mlx_xpm_file_to_image(vars.mlx, wall, &img_width, &img_height);
                mlx_put_image_to_window(vars.mlx, vars.win, img_ptr, k, y);
            }
            if (matrix[i][j] == 'P')
            {
                img_ptr = mlx_xpm_file_to_image(vars.mlx, player, &img_width, &img_height);
                mlx_put_image_to_window(vars.mlx, vars.win, img_ptr, k, y);
            }
            if (matrix[i][j] == 'C')
            {
                img_ptr = mlx_xpm_file_to_image(vars.mlx, burger, &img_width, &img_height);
                mlx_put_image_to_window(vars.mlx, vars.win, img_ptr, k, y);
            }
            if (matrix[i][j] == 'E')
            {
                img_ptr = mlx_xpm_file_to_image(vars.mlx, door, &img_width, &img_height);
                mlx_put_image_to_window(vars.mlx, vars.win, img_ptr, k, y);
            }
            k += 40;
        }
        y += 40;
    }
    mlx_do_sync(vars.mlx);
    mlx_loop(vars.mlx);
    return 0;
}

int main(int argc, char **argv)
{
    char **matrix;
    int fd;
    int rows;
    int cols;
    t_RowsCols result;
    t_utilities util;

    util.state = 40;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        result = matrix_row_col(fd);

        rows = result.rows;
        cols = result.cols;
        matrix = create_matrix(argv[1], fd, rows, cols);

        if (border_character_check(matrix, rows, cols) == 1 && inner_character_check(matrix, rows, cols) == 1)
        {
            // printf("test1\n");
            // wall_to_window(matrix, rows, cols);
            util = start(fd, argv[1]);
            // printf("test2\n");
            util.screen.win = mlx_new_window(util.screen.mlx, cols * 40, rows * 40, "so long");
            util.screen.img.ptr = mlx_new_image(util.screen.mlx,
                                            40 * cols, 40 * rows);
            util.screen.img.addr = mlx_get_data_addr(util.screen.img.ptr,
                                                 &util.screen.img.bpp, &util.screen.img.linelen, &util.screen.img.endian);
            mlx_hook(util.screen.win, 2, 1L << 0, ft_mlx_pressed, &(util.keys));
            // mlx_hook(util.screen.win, 3, 1L << 1, ft_mlx_released, &(util.keys));

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