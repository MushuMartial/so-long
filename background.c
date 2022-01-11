/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:07:40 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/11 16:01:32 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	background(t_data *data, t_img *img)
{
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->len)
		{
			if (data->map[data->y][data->x] == '1')
				img->img = mlx_xpm_file_to_image(data->mlx, "./lava.xpm",
						&img->size, &img->size);
			else if (data->map[data->y][data->x] == '0' ||
			data->map[data->y][data->x] == 'P' ||
			data->map[data->y][data->x] == 'C')
				img->img = mlx_xpm_file_to_image(data->mlx, "./floor.xpm",
						&img->size, &img->size);
			else if (data->map[data->y][data->x] == 'E')
				img->img = mlx_xpm_file_to_image(data->mlx, "./exit.xpm",
						&img->size, &img->size);
			mlx_put_image_to_window(data->mlx, data->win, img->img,
				data->x * 64, data->y * 64);
			data->x++;
		}
		data->y++;
	}
}

void	characters(t_data *data, t_img *img)
{
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->len)
		{
			if (data->map[data->y][data->x] == 'P')
			{
				img->img = mlx_xpm_file_to_image(data->mlx, "./hero.xpm",
						&img->size, &img->size);
				mlx_put_image_to_window(data->mlx, data->win, img->img,
					data->x * 64, data->y * 64);
			}
			else if (data->map[data->y][data->x] == 'C')
			{
				img->img = mlx_xpm_file_to_image(data->mlx, "./objet.xpm",
						&img->size, &img->size);
				mlx_put_image_to_window(data->mlx, data->win, img->img,
					data->x * 64, data->y * 64);
			}
			data->x++;
		}
		data->y++;
	}
}
