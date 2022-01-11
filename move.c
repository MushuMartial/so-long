/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:44:00 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/11 17:18:31 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_mlx(t_data	*data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_all(data);
	return (0);
}

void	move_player(t_data *data, t_img *img, int y, int x)
{
	img->img_e = mlx_xpm_file_to_image(data->mlx, "./exit.xpm",
			&img->size, &img->size);
	img->img_h = mlx_xpm_file_to_image(data->mlx, "./hero.xpm",
			&img->size, &img->size);
	img->img_f = mlx_xpm_file_to_image(data->mlx, "./floor.xpm",
			&img->size, &img->size);
	if (data->map[y][x] == 'C')
		data->count_c--;
	if (data->map[y][x] == 'E')
		data->map[y][x] = 'D';
	else
		data->map[y][x] = 'P';
	mlx_put_image_to_window(data->mlx, data->win, img->img_h, x * 64, y * 64);
	if (data->map[data->y][data->x] == 'D')
	{
		mlx_put_image_to_window(data->mlx, data->win, img->img_e,
			data->x * 64, data->y * 64);
		data->map[data->y][data->x] = 'E';
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, img->img_f,
			data->x * 64, data->y * 64);
	data->x = x;
	data->y = y;
	data->walk++;
}

int	key_hook(int keycode, t_data *data, t_img *img)
{
	if (keycode == 53)
		exit_mlx(data);
	if (keycode == 0 && data->map[data->y][data->x - 1] != '1')
	{
		move_player(data, img, data->y, data->x - 1);
		printf("you did : %d footsteps\n", data->walk);
	}
	else if (keycode == 2 && data->map[data->y][data->x + 1] != '1')
	{
		move_player(data, img, data->y, data->x + 1);
		printf("you did : %d footsteps\n", data->walk);
	}
	else if (keycode == 13 && data->map[data->y - 1][data->x] != '1')
	{
		move_player(data, img, data->y - 1, data->x);
		printf("you did : %d footsteps\n", data->walk);
	}
	else if (keycode == 1 && data->map[data->y + 1][data->x] != '1')
	{
		move_player(data, img, data->y + 1, data->x);
		printf("you did : %d footsteps\n", data->walk);
	}
	if (data->map[data->y][data->x] == 'D' && data->count_c == 0)
		free_all(data);
	return (0);
}
