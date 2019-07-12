/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:28:09 by amamy             #+#    #+#             */
/*   Updated: 2019/07/12 13:20:06 by amamy            ###   ########.fr       */
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
	data->mid = data->coo[0] - data->coo_op[0];
	if (data->mid < 0)
		data->mid = data->mid * -1;
	dprintf(data->fd2, "Mid stored : %d\n", data->mid);
}

static void ft_get_first_piece(t_data *data)
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

static	void ft_get_aim(t_data *data)
{
	int mid;
	int i;
	int ret;

	i = 0;
	ret = 0;
	mid = (data->map_size[0] / 2) - 3;
	dprintf(data->fd2, "\nGet aim : \ndata->coo[0] : %d\n\n", data->coo[0]);
	if (data->aim & CUT)
	{
		dprintf(data->fd2, "GO FOR FILL\n");
		while (i <= 5 && (ret = ft_line_mine(data, data->map[mid])) != 1)
			i++;
		if (ret == 1)
		{
			data->aim |= FILL;
			dprintf(data->fd2, "***** FILL *****");
		}
	}
	else if(((data->aim & UP && data->coo[0] <= mid)
	|| (data->aim & DOWN && data->coo[0] >= mid))  && !(data->aim & FILL))
	{
		data->aim |= CUT;
		dprintf(data->fd2, "***** CUT *****");
	}
	else if (data->coo[0] > mid && !(data->aim & CUT) && !(data->aim & FILL))
	{
		data->aim |= UP;
		dprintf(data->fd2, "***** UP *****");
	}
	else if (data->coo[0] < mid && !(data->aim & CUT) && !(data->aim & FILL))
	{
		data->aim |= DOWN;
		dprintf(data->fd2, "***** DOWN *****");
	}
}

void ft_analyse(t_data *data)
{
	if (data->coo[0] == 0)
		ft_get_first_piece(data);
	// ft_putstr("analyse\n");
	ft_get_aim(data);
}
