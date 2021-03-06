/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:02:51 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/13 14:07:05 by tmartial         ###   ########.fr       */
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
	check_len(file, data);
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

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL && i < data->height)
		free(data->map[i++]);
	free(data->map);
	exit(0);
}

void	check_len(char *file, t_data *data)
{
	int		fd;
	char	*buffer;

	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		exit(0);
	buffer[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		exit(0);
	}
	check_len2(fd, buffer, data);
	free(buffer);
	close(fd);
}

void	check_len2(int fd, char *buffer, t_data *data)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = read(fd, buffer, 1);
		if (buffer[0] == '\n' && i != data->len && j != data->height)
		{
			write(2, "Error\nWrong map format", 22);
			exit(0);
		}
		if (buffer[0] == '\n')
		{	
			i = -1;
			j++;
		}
		i++;
	}
}
