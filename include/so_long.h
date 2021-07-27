#ifndef SO_LONG_H
#define SO_LONG_H

#define BUFFER_SIZE 1

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
// #include "../libft/libft.h"

typedef struct s_RowsCols
{
    int     rows;
    int     cols;
}           t_RowsCols;

typedef struct s_keys
{
    int     up;
    int     down;
    int     right;
    int     left;
    int     check;
}           t_keys;

typedef struct s_map
{
    int     width;
    int     height;
    char    **matrix;
}           t_map;

typedef struct s_img
{
    void	    *ptr;
	char		*addr;
	int			bpp;
	int			linelen;
	int			endian;
	int			width;
	int			height;
}               t_img;

typedef struct s_screen
{
    void        *mlx;
    void        *win;
    // void        *lose;
    // void        *victor;
    t_img       img;
}               t_screen;

typedef struct s_player
{
    int         x;
    int         y;
    int         items;
    int         goal;
    int         steps;
}               t_player;

typedef struct s_exit
{
    int         x;
    int         y;
}               t_exit;

typedef struct s_utilities
{
    int         i;
    int         j;
    int         x;
    int         y;
    int			texx;
	int			texy;
    int			unitsize;
    int		    state; //game state(finished or not)
    t_img		sprite;
    t_keys      keys;
    t_player    player;
    t_screen    screen;
    t_exit      exit;
    t_map       map;
    t_img		tfloor;
    t_img       tplayer;
    t_img       twall;
    t_img       tfood;
    t_img       texit;
}		        t_utilities;

t_RowsCols      matrix_row_col(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
int				get_next_line(int fd, char **line);
char			*ft_strchr(char *s, int c);
char            *leftover(char *tmp);
char *the_line(char *tmp);
char **create_matrix(char *path, int fd, int rows, int cols);
void matrix_rows_cols(int fd, int rows, int cols);
int inner_character_check(char **matrix, int rows, int cols);
int border_character_check(char **matrix, int rows, int cols);
void ft_load_images(t_utilities *util);
void ft_startvalues(t_utilities *util);
int	ft_mlx_pressed(int keycode, t_keys *keys);
int	ft_mlx_released(int keycode, t_keys *keys);
t_utilities start(int fd, char *argv);
int	ft_render(t_utilities *util);
void	ft_putmoves(t_utilities *util);
void	ft_checkinput1(t_utilities *res);
void	ft_checkinput2(t_utilities *res);
void	ft_checkinput3(t_utilities *res);
void	ft_checkinput4(t_utilities *res);
void	ft_mlx_draw_unit(t_utilities *res, int i, int j);
void    ft_setmatrixcharacters(t_utilities *util);
void	ft_exit(char *str);
void	ft_initplayer(t_utilities *util, int posx, int posy);
void	ft_initexit(t_utilities *util, int posx, int posy);
void	ft_selectsprite(t_utilities *res, int i, int j);
void	ft_putspritepixel(t_utilities *res, int i, int j);
int     check_norms(t_utilities util);
#endif
