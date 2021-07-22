#include "../include/so_long.h"

void ft_startvalues(t_utilities *util)
{
  util->screen.mlx = mlx_init();
  util->exit.x = -1;
  util->exit.y = -1;
  util->player.x = -1;
  util->player.y = -1;
  util->player.items = 0;
  // util->player.moves = 0;
  // util->time = 0;
  util->state = 1;
  util->keys.check = 1;
}

void ft_load_images(t_utilities *util)
{
  util->twall.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/wall.xpm", 
    &util->twall.width, &util->twall.height);
  util->twall.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/wall.xpm",
    &util->twall.width, &util->twall.height);
  util->twall.addr = mlx_get_data_addr(util->twall.ptr, &util->twall.bpp,
    &util->twall.linelen, &util->twall.endian);
  
  if (!(util->twall.ptr))
    exit(0);

  util->tplayer.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/player.xpm",
    &util->tplayer.width, &util->tplayer.height);
  util->tplayer.addr = mlx_get_data_addr(util->tplayer.ptr, &util->tplayer.bpp,
    &util->tplayer.linelen, &util->tplayer.endian);
  util->tfood.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/burger.xpm",
    &util->tfood.width, &util->tfood.height);
  util->tfood.addr = mlx_get_data_addr(util->tfood.ptr, &util->tfood.bpp,
    &util->tfood.linelen, &util->tfood.endian);
  util->texit.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/exit.xpm",
    &util->texit.width, &util->texit.height);
  util->texit.addr = mlx_get_data_addr(util->texit.ptr, &util->texit.bpp,
    &util->texit.linelen, &util->texit.endian);
}

t_utilities start(int fd, char *argv)
{
  t_utilities util;
  int rows;
  int cols;
  t_RowsCols result;
  result = matrix_row_col(fd);
  // printf("test3\n");

  rows = result.rows;
  cols = result.cols;
  // printf("test4\n");

  util.map.matrix = create_matrix(argv, fd, rows, cols);
  // printf("test5\n");

  util.map.width = rows;
  util.map.height = cols;

  ft_startvalues(&util);
  ft_load_images(&util);
  // printf("test6\n");

  return util;
}