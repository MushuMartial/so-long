/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:08:41 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/13 13:55:50 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	void	*img_h;
	char	*addr_h;
	void	*img_f;
	char	*addr_f;
	void	*img_e;
	char	*addr_e;
	char	*path;
	int		size;
}				t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	**map;
	int		len;
	int		height;
	int		x;
	int		y;
	int		count_c;
	int		walk;
}				t_data;

/* main */
void	parser(char *file, t_data *data);
int		ft_strlen(char *s);
void	free_all(t_data *data);
void	check_len(char *file, t_data *data); //len of all lines
void	check_len2(int fd, char *buffer, t_data *data);

/* background */
void	background(t_data *data, t_img *img); //print background
void	characters(t_data *data, t_img *img); //print elements

/* move */
int		exit_mlx(t_data	*data); //mouse click exit
void	move_player(t_data *data, t_img *img, int y, int x); //move player
int		key_hook(int keycode, t_data *data, t_img *img); //key_hook moves

/* check */
void	check_format(t_data *data); //letters im map
void	check_char(t_data *data, int letter); //num of elem
void	check_wall(t_data *data); //wall
void	check_arg(char *file); //map .ber input
void	player_pos(t_data *data); //look player pos

/* parser */
void	init_len_height(char *file, t_data *data);//find len&height
void	map_init(t_data *data);//malloc **map
void	make_map(char *file, t_data *data); //read map
void	fill_map(int fd, t_data *data, char *buffer);//fill **map
void	fill_map2(t_data *data, char *buffer);

#endif