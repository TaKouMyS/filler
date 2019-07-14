/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:09:26 by amamy             #+#    #+#             */
/*   Updated: 2019/07/13 20:09:34 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

static void ft_store_first_piece(t_data *data, int tmp[4])
{
	// printf("coo just stored : Y : %d | x : %d\n", data->coo[0], data->coo[1]);
	if (data->player_number == 1)
	{
		data->coo[0] = tmp[0];
		data->coo[1] = tmp[1] - 4;
		data->coo_op[0] = tmp[2];
		data->coo_op[1] = tmp[3] - 4;
	}
	if (data->player_number == 2)
	{
		data->coo[0] = tmp[2];
		data->coo[1] = tmp[3] - 4;
		data->coo_op[0] = tmp[0];
		data->coo_op[1] = tmp[1] - 4;
	}
	data->mid = (data->coo[0] + data->coo_op[0]) / 2;
	dprintf(data->fd2, "Mid stored : %d\n", data->mid);
}

void ft_get_first_piece(t_data *data)
{
	int y;
	int x;
	int tmp[4];

	y = 0;
	x = 0;
	// ft_putstr("ft_get_first_piece\n");
	while (y < data->map_size[0])
	{
		if (data->map[y][x] == 'O' || data->map[y][x] == 'o')
		{
			tmp[0] = y;
			tmp[1] = x;
			// ft_putstr("ft_get_first_piece1\n");
		}
		else if (data->map[y][x] == 'X' || data->map[y][x] == 'x')
		{
			// ft_putstr("ft_get_first_piece1 - 5\n");
			tmp[2] = y;
			tmp[3] = x;
		}
		// printf("y : %d | x  %d\n", y , x);
		if (data->map[y][x++] == '\0')
		{
			x = 0;
			y++;
		}
	}
	// ft_putstr("ft_get_first_piece3\n");
	ft_store_first_piece(data, tmp);
	// ft_putstr("ft_get_first_piece4\n");
}
