/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:17:05 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/06 16:23:43 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	init_len_height(char *file, t_data *data)
{
	int fd;
	char *buffer;
	int ret;
	
	buffer = malloc(sizeof(char) * 2);
	if(!buffer)
		exit(0);
	buffer[1] = '\0';
	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (ret == 1)
	{
		ret = read(fd, buffer, 1);
		data->len++;
		if (buffer[0] == '\n')
		{
			data->height++;
		}
	}
	data->len /= data->height;
	data->len--;
}

void	map_init(t_data *data)
{
	int	i;
	
	i = 0;
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		exit(0);
	while (i < data->height)
	{
		data->map[i] = malloc(sizeof(char) * (data->len + 1));
		if (!data->map[i])
			exit(0);
		data->map[i++][data->len] = '\0';
	}
}

void fill_map(int fd, t_data *data, char *buffer)
{
	int ret;
	int i;
	int j;

	i = 0;
	j = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = read(fd, buffer, 1);
		if (i == data->len && buffer[0] != '\n' && buffer[0] != '\0')
			return;
		if (buffer[0] == '\n')
		{	
			j++;
			i = 0;
		}
		else
        {
			data->map[j][i++] = buffer[0];
            write(1,"b\n",2);
        }
	}
}
void make_map(char *file, t_data *data)
{
	int fd;
	char *buffer;
	
	buffer = malloc(sizeof(char) * 2);
	if(!buffer)
		exit(0);
	buffer[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(0);
	fill_map(fd, data, buffer);
}
/*
void    check_map(char *map, *)
{
    int fd;
    int ret;
    char *buffer;
    int height;
    int lenght;
    
    ret = 1;
    buffer = malloc(sizeof(char) * 2);
    if (!buffer)
        exit(0);
    buffer[ret] = '\0';
    fd = open(map, O_RDONLY);
    if (fd < 0)
        exit(0);
    while (ret > 0)
    {
        ret = read(fd, buffer, 1);
        if (buffer[0] != '1' & buffer[0] != '0' & buffer[0] != '\n'
        & buffer[0] != 'C' & buffer[0] != 'E' & buffer[0] != 'P')
        {
            printf("error\n");
            exit(0);
        }
    }
    map_fill(map, 'C', 0);
    map_fill(map, 'P', 0);
    map_fill(map, 'E', 0);
}

void map_fill(char *map, int letter, int num)
{
    int fd;
    int ret;
    char *buffer;
    
    ret = 1;
    buffer = malloc(sizeof(char) * 2);
    if (!buffer)
        exit(0);
    buffer[ret] = '\0';
    fd = open(map, O_RDONLY);
    if (fd < 0)
        exit(0);
    while (ret > 0)
    {
        ret = read(fd, buffer, 1);
        if (buffer[0] == letter)
            num++;
    }
    if (num > 1)
    {
        printf("error\n");
        exit(0);
    }
}*/