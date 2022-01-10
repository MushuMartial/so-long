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
	free_all(data);
	return (0);
}

void	move_player(t_data *data, t_img *img, int y, int x)
{
	if (data->map[y][x] == 'C')
		data->count_c--;
	if (data->map[y][x] == 'E')
		data->map[y][x] = 'D';
	else
		data->map[y][x] = 'P';
	mlx_put_image_to_window(data->mlx, data->win, img->img_h, x * 64, y * 64);
	if (data->map[y][x] == 'D')
	{
		mlx_put_image_to_window(data->mlx, data->win, img->img_e, x * 64, y * 64);
		data->map[y][x] = 'E';
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, img->img_f, x * 64, y * 64);
	data->x = x;
	data->y = y;
	data->walk++:
	printf("you did : %d footsteps", data->walk);
}

int	key_hook(int keycode, t_data *data, t_img *img)
{
	img->img_e = mlx_xpm_file_to_image(data->mlx, "./exit.xpm", &img->size, &img->size);
	img->img_h = mlx_xpm_file_to_image(data->mlx, "./hero.xpm", &img->size, &img->size);
	img->img_f = mlx_xpm_file_to_image(data->mlx, "./floor.xpm", &img->size, &img->size);
	if (keycode == 53)
		free_all(data);
	if (keycode == 0 && data->map[data->y][data->x - 1] != '1')
		move_player(data, img, data->y, data->x - 1);

	else if (keycode == 2 && data->map[data->y][data->x + 1] != '1')
		move_player(data, img, data->y, data->x + 1);

	else if (keycode == 13 && data->map[data->y + 1][data->x] != '1')
		move_player(data, img, data->y + 1, data->x);

	else if (keycode == 1 && data->map[data->y - 1][data->x] != '1')
		move_player(data, img, data->y - 1, data->x);

	if (data->map[data->y][data->x] == 'D' && data->count_c == 0)
		free_all(data);
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
