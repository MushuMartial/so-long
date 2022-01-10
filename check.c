/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:48:15 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/08 13:41:26 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void check_format(t_data *data)
{
	int i;
	int j;

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
				printf("error map format\n");
				exit(0);
			}
            i++;
		}
		j++;
	}
}

void	check_char(t_data *data, int letter)
{
	int i;
	int j;
	int count;

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
	if (count == 0)
	{
		printf("error in map\n");
		exit(0);
	}
	if (count > 1 && letter == 'P')
	{
		printf("error player number\n");
		exit(0);
	}
}

void check_wall(t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1' && data->map[i][data->len] != '1')
		{
			printf("error wall\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < data->len)
	{
		if (data->map[0][i] != '1' | data->map[data->height - 1][i] != '1')
		{
			printf("error wall\n");
			exit(0);
		}
		i++;
	}
}