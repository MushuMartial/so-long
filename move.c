/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:10:20 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/10 16:58:51 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int exit_mlx(t_data	*data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data, t_img *img)
{
	img->img_e = mlx_xpm_file_to_image(data->mlx, "./exit.xpm", &img->size, &img->size);
	img->img_h = mlx_xpm_file_to_image(data->mlx, "./hero.xpm", &img->size, &img->size);
	img->img_f = mlx_xpm_file_to_image(data->mlx, "./floor.xpm", &img->size, &img->size);
	if (keycode == 53)
		exit(0);
	if (keycode == 0 && data->map[data->y][data->x - 1] != '1')
	{
		if (data->map[data->y][data->x - 1] == 'C')
			data->count_c--;
		if (data->map[data->y][data->x - 1] == 'E')
			data->map[data->y][data->x - 1] = 'D';
		else
			data->map[data->y][data->x - 1] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, img->img_h, (data->x - 1) * 64, data->y * 64);
		if (data->map[data->y][data->x] == 'D')
		{
			mlx_put_image_to_window(data->mlx, data->win, img->img_e, data->x * 64, data->y * 64);
			data->map[data->y][data->x] = 'E';
		}
		else
			mlx_put_image_to_window(data->mlx, data->win, img->img_f, data->x * 64, data->y * 64);
		data->x--;
		
	}
	else if (keycode == 2 && data->map[data->y][data->x + 1] != '1')
	{
		if (data->map[data->y][data->x + 1] == 'C')
			data->count_c--;
		if (data->map[data->y][data->x + 1] == 'E')
			data->map[data->y][data->x + 1] = 'D';
		else
			data->map[data->y][data->x + 1] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, img->img_h, (data->x + 1) * 64, data->y * 64);
		if (data->map[data->y][data->x] == 'D')
		{
			mlx_put_image_to_window(data->mlx, data->win, img->img_e, data->x * 64, data->y * 64);
			data->map[data->y][data->x] = 'E';
		}
		else
			mlx_put_image_to_window(data->mlx, data->win, img->img_f, data->x * 64, data->y * 64);
		data->x++;
	}
	else if (keycode == 13 && data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'C')
			data->count_c--;
		if (data->map[data->y - 1][data->x] == 'E')
			data->map[data->y - 1][data->x] = 'D';
		else
			data->map[data->y - 1][data->x ] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, img->img_h, data->x * 64, (data->y - 1)* 64);
		if (data->map[data->y][data->x] == 'D')
		{
			mlx_put_image_to_window(data->mlx, data->win, img->img_e, data->x * 64, data->y * 64);
			data->map[data->y][data->x] = 'E';
		}
		else
			mlx_put_image_to_window(data->mlx, data->win, img->img_f, data->x * 64, data->y * 64);
		data->y--;
	}
	else if (keycode == 1 && data->map[data->y + 1][data->x] != '1')
	{
		if (data->map[data->y + 1][data->x] == 'C')
			data->count_c--;
		if (data->map[data->y + 1][data->x] == 'E')
			data->map[data->y + 1][data->x] = 'D';
		else
			data->map[data->y + 1][data->x] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, img->img_h, data->x * 64, (data->y + 1) * 64);
		if (data->map[data->y][data->x] == 'D')
		{
			mlx_put_image_to_window(data->mlx, data->win, img->img_e, data->x * 64, data->y * 64);
			data->map[data->y][data->x] = 'E';
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->win, img->img_f, data->x * 64, data->y * 64);
		}
		data->y++;
	}
	if (data->map[data->y][data->x] == 'D' && data->count_c == 0)
	{	
		exit(0);
	}
	return (0);
}

void player_pos(t_data *data)
{
    int i;
	int j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			if (data->map[j][i] == 'P')
			{
                data->x = i;
                data->y = j;
			}
            else if (data->map[j][i] == 'C')
                data->count_c++;
            i++;
		}
		j++;
	}
}
