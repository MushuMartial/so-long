/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:44:29 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/12 15:39:37 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_len_height(char *file, t_data *data)
{
	int		fd;
	char	*buffer;
	int		ret;

	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		exit(0);
	buffer[1] = '\0';
	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		exit(0);
	}
	while (ret == 1)
	{
		ret = read(fd, buffer, 1);
		data->len++;
		if (buffer[0] == '\n')
			data->height++;
	}
	data->len /= data->height;
	data->len--;
	free(buffer);
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
			free_all(data);
		data->map[i++][data->len] = '\0';
	}
}

void	fill_map(int fd, t_data *data, char *buffer)
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = read(fd, buffer, 1);
		if (buffer[0] == '\n' && j + 1 == data->height)
			return ;
		if (buffer[0] == '\n')
		{	
			j++;
			i = -1;
		}
		else
			data->map[j][i] = buffer[0];
		i++;
	}
}

void	fill_map2(t_data *data, char *buffer)
{
	free(buffer);
	write(2, "Error\nWrong map format", 22);
	free_all(data);
}

void	make_map(char *file, t_data *data)
{
	int		fd;
	char	*buffer;

	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		free_all(data);
	buffer[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		free_all(data);
	}
	fill_map(fd, data, buffer);
	free(buffer);
}
