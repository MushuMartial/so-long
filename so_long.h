#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "mlx.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		*size;
}				t_img;


typedef struct	s_data {
	void	*mlx;
	void	*win;
	char 	**map;
	int		len;
	int		height;
}				t_data;

/* mlx utils */
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color); //Put pixel

/* hooks utils*/
//int	key_hook(int keycode, t_vars *vars); //Print Keyes
//int	close_w(int keycode, t_vars *vars); //Close Window

/* check */
void check_format(t_data *data);

/* parser */
void	parser(char *file);
void	init_len_height(char *file, t_data *data);
void	map_init(t_data *data);
void make_map(char *file, t_data *data);
void fill_map(int fd, t_data *data, char *buffer);


#endif