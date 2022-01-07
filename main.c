/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:02:51 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/07 18:35:13 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* s_img {
	void	*img;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		size;
}t_img;
s_data {
	void	*mlx;
	void	*win;
	char	**map;
	int		len;
	int		height;
	int 	x;
	int 	y;
	2560, 1396
}				t_data;*/

int	main(int argc, char *argv[])
{
	t_data	data;
	t_img	img;
	
	if (argc != 2)
		perror(strerror(2));
	else
	{
		parser(argv[1], &data);
		data.mlx = mlx_init();
		img.size = 32;
		data.win = mlx_new_window(data.mlx, 1920, 1080, "So long");
		background(&data, &img);
		mlx_loop(data.mlx);
	}
}

void	parser(char *file, t_data *data)
{
	
	data->height = 1;
	data->len = 0;
	init_len_height(file, data);
	map_init(data);
	if (data->height < 3)
		exit(0);
	make_map(file, data);
	check_format(data);
	check_char(data, 'C');
	check_char(data, 'P');
	check_char(data, 'E');
	check_wall(data);
}


