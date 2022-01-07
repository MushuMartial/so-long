#include "so_long.h"

void    background(t_data *data, t_img *img)
{
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x++ < data->len)
		{
			if (data->map[data->y][data->x] == '1')
			{
				img->img = mlx_xpm_file_to_image(data->mlx, "./water.xpm", &img->size, &img->size);
				img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size, &img->size);
			}
            else if (data->map[data->y][data->x] == '0')
			{
				img->img = mlx_xpm_file_to_image(data->mlx, "./grass.xpm", &img->size, &img->size);
				img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size, &img->size);
			}
			else if (data->map[data->y][data->x] == 'E')
			{
				img->img = mlx_xpm_file_to_image(data->mlx, "./grass.xpm", &img->size, &img->size);
				img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size, &img->size);
			}
			mlx_put_image_to_window(data->mlx, data->win, img->img, data->x * 32, data->y * 32);
		}
		data->y++;
	}
}
