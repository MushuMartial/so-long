/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:48:15 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/12 11:30:54 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_format(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			if (data->map[j][i] != 'C' && data->map[j][i] != 'P'
			&& data->map[j][i] != 'E' && data->map[j][i] != '0'
			&& data->map[j][i] != '1' && data->map[j][i] != '\0'
			&& data->map[j][i] != '\n')
			{
				write(2, "Error\nWrong map format", 22);
				free_all(data);
			}
			i++;
		}
		j++;
	}
}

void	check_char(t_data *data, int letter)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = -1;
	while (++j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
			if (data->map[j][i] == letter)
				count++;
			i++;
		}
	}
	if ((count > 1 && letter == 'P') || count == 0)
	{
		write(2, "Error\nWrong map format", 22);
		free_all(data);
	}
}

void	check_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->len - 1] != '1')
		{
			write(2, "Error\nWrong map format wall", 27);
			free_all(data);
		}
		i++;
	}
	i = 0;
	while (i < data->len)
	{
		if (data->map[0][i] != '1' || data->map[data->height - 1][i] != '1')
		{
			write(2, "Error\nWrong map format wall", 27);
			free_all(data);
		}
		i++;
	}
}

void	check_arg(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5)
	{
		write(2, "Error\nWrong map format .ber", 27);
		exit(0);
	}
	if (file[i - 1] != 'r' || file[i - 2] != 'e' || file[i - 3] != 'b'
		|| file[i - 4] != '.')
	{
		write(2, "Error\nWrong map format .ber", 27);
		exit(0);
	}
}

void	player_pos(t_data *data)
{
	int	i;
	int	j;

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
