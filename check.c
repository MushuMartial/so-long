/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:48:15 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/06 15:48:15 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void check_format(t_data *data)
{
	int i;
	int j;

	j = -1;
	while (++j < data->height)
	{
		i = 0;
		while (i < data->len)
		{
            write(1, "b\n", 2);
			if (data->map[j][i] != 'C' && data->map[j][i] != 'P'
			&& data->map[j][i] != 'E' && data->map[j][i] != '0'
			&& data->map[j][i] != '1' && data->map[j][i] != '\0')
				exit(0);
            i++;
		}
	}
    write(1, "a\n", 2);
}