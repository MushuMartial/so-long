/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:02:51 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/10 16:40:58 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* s_img {
	void	*img;
	char	*addr;
	char	*path;
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
	int		count_c;
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
		img.size = 64;
		data.count_c = 0;
		data.walk = 0;
		data.win = mlx_new_window(data.mlx, data.len * 64, data.height * 64, "so long");
		background(&data, &img);
		characters(&data, &img);
		player_pos(&data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
		mlx_loop(data.mlx);
	}
}

void	check_arg(char *file)
{
	int i;

	i = ft_strlen(file);
	if (i < 5)
		exit(0);
	if (file[i -1] != 'r')
		exit(0);
	if (file[i -2] != 'e')
		exit(0);
	if (file[i -3] != 'b')
		exit(0);
	if (file[i -4] != '.')
		exit(0);
	
}

void	parser(char *file, t_data *data)
{
	data->height = 1;
	data->len = 0;
	check_arg(file);
	init_len_height(file, data);
	if (data->height < 3)
		exit(0);
	map_init(data);
	make_map(file, data);
	check_format(data);
	if (data->x > 40 | data->y > 21)
		free_all(data);
	check_char(data, 'C');
	check_char(data, 'P');
	check_char(data, 'E');
	check_wall(data);
}
