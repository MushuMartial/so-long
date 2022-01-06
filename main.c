/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:02:51 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/06 16:20:54 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* s_img {
	void	*img;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		*size;
}t_img;
s_data {
	void	*mlx;
	void	*win;
	char	**map;
	int		len;
	int		height;
}				t_data;*/

int	main(int argc, char *argv[])
{
	if (argc != 2)
		perror(strerror(2));
	else
		parser(argv[1]);
}

void	parser(char *file)
{
	t_data	data;
	t_img	img;
	
	data.height = 1;
	data.len = 0;
	map_init(&data);
	init_len_height(file, &data);
	if (data.height < 3)
		exit(0);
	make_map(file, &data);
	write(1,"a\n",2);
	if (data.map[0][0] == '1')
		write(1,"b\n",2);
	//check_format(&data);
}


/*
int	main(int argc, char *argv[])
{
	t_data	data;
	t_img	img;
	
	char	*relative_path1 = "./grass.xpm";
	char	*relative_path2 = "./water.xpm";
	img.line_length = 32;
	img.endian = 32;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "So long");
	img.img = mlx_xpm_file_to_image(data.mlx, relative_path1, &img.line_length, &img.endian);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	void	*img_water;
	char	*addr_water;
	img_water = mlx_xpm_file_to_image(data.mlx, relative_path2, &img.line_length, &img.endian);
	addr_water = mlx_get_data_addr(img_water, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 0;
	int y = 32;
	int fd;
    int ret;
    char *buffer;
    
    ret = 1;
    buffer = malloc(sizeof(char) * 2);
    if (!buffer)
        exit(0);
    buffer[ret] = '\0';
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        exit(0);
    while (ret > 0)
    {
        ret = read(fd, buffer, 1);
        if (buffer[0] == '0' | buffer[0] == 'P' | buffer[0] == 'C' | buffer[0] == 'E')
			mlx_put_image_to_window(data.mlx, data.win, img.img, x, y);
		if (buffer[0] == '1')
			mlx_put_image_to_window(data.mlx, data.win, img_water, x, y);
		x += 32;
		if (buffer[0] == '\n')
		{
			y += 32;
			x = 0;
		}
    }
	mlx_loop(data.mlx);
}*/


/*int	main(int argc, char *argv[])
{
	t_data	data;
	t_img	img;
	int fd;
	
	if (argc != 2)
		perror(strerror(2));
	else
	{
		check_map(argv[1]);
	}
}*/
/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/
