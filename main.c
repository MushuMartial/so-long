/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:02:51 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/11 16:59:32 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_img	img;

	if (argc != 2)
		write(2, "Error\ninvalid args", 18);
	else
	{
		parser(argv[1], &data);
		data.mlx = mlx_init();
		img.size = 64;
		data.count_c = 0;
		data.walk = 0;
		data.win = mlx_new_window(data.mlx, data.len * 64, data.height * 64,
				"so_long");
		background(&data, &img);
		characters(&data, &img);
		player_pos(&data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
		mlx_loop(data.mlx);
	}
}

void	parser(char *file, t_data *data)
{
	data->height = -1;
	data->len = 0;
	check_arg(file);
	init_len_height(file, data);
	if (data->height < 3)
	{
		write(2, "Error\nmap to small", 18);
		exit(0);
	}
	map_init(data);
	make_map(file, data);
	check_format(data);
	if (data->len > 40 || data->height > 21)
		free_all(data);
	check_char(data, 'C');
	check_char(data, 'P');
	check_char(data, 'E');
	check_wall(data);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL && i < data->height)
		free(data->map[i++]);
	free(data->map);
	exit(0);
}
