#include "../include/so_long.h"

void ft_startvalues(t_utilities *util)
{
  util->screen.mlx = mlx_init();
  util->exit.x = -1;
  util->exit.y = -1;
  util->player.x = -1;
  util->player.y = -1;
  util->player.items = 0;
  util->player.steps = 0;
  // util->time = 0;
  util->state = 1;
  util->keys.check = 1;
}
void	ft_initplayer(t_utilities *util, int posx, int posy)
{
	if (!(util->player.x < 0 && util->player.y < 0))
		// ft_exit("Multiple players are not permitted."); 
    exit(0);
	util->player.x = posx;
	util->player.y = posy;
}

void	ft_initexit(t_utilities *util, int posx, int posy)
{
	if (!(util->exit.x < 0 && util->exit.y < 0))
		exit(0);
    // ft_exit("Multiple exits are not permitted.");
	util->exit.x = posx;
	util->exit.y = posy;
}


void ft_load_images(t_utilities *util)
{
  util->twall.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/wall.xpm",
    &util->twall.width, &util->twall.height);
  util->twall.addr = mlx_get_data_addr(util->twall.ptr, &util->twall.bpp,
    &util->twall.linelen, &util->twall.endian);
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
  util->tfloor.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/floor.xpm",
			&(util->tfloor.width), &(util->tfloor.height));
	util->tfloor.addr = mlx_get_data_addr(util->tfloor.ptr,
			&util->tfloor.bpp, &util->tfloor.linelen, &util->tfloor.endian);
}

t_utilities start(int fd, char *argv)
{
  t_utilities util;
  t_RowsCols result;
  result = matrix_row_col(fd);
  
  util.map.height = result.rows;
  util.map.width = result.cols;
  util.unitsize = 40;
  ft_startvalues(&util);
  util.map.matrix = create_matrix(argv, fd, util.map.height, util.map.width);

  ft_setmatrixcharacters(&util);
  ft_load_images(&util);

  return util;
}