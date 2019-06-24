/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:28:09 by amamy             #+#    #+#             */
/*   Updated: 2019/06/24 14:34:45 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

static void ft_store_first_piece(t_data *data, int tmp[4])
{
	if (data->player_number == 1)
	{
		data->coo_me[0] = tmp[0] -1;
		data->coo_me[1] = tmp[1] - 4;
		data->coo_you[0] = tmp[2] -1;
		data->coo_you[1] = tmp[3] - 4;
	}
	if (data->player_number == 2)
	{
		data->coo_me[0] = tmp[2] -1;
		data->coo_me[1] = tmp[3] - 4;
		data->coo_you[0] = tmp[0] -1 ;
		data->coo_you[1] = tmp[1] - 4;
	}
}

static void ft_get_first_piece(t_data *data)
{
	int y;
	int x;
	int tmp[4];

	y = 0;
	x = 0;
	while (y < data->map_size[0] + 1)
	{
		if (data->map[y][x] == 'O')
		{
			tmp[0] = y;
			tmp[1] = x;
		}
		else if (data->map[y][x] == 'X')
		{
			tmp[2] = y;
			tmp[3] = x;
		}
		if (data->map[y][x++] == '\0')
		{
			x = 0;
			y++;
		}
	}
	ft_store_first_piece(data, tmp);
}

static	void ft_get_aim(t_data *data)
{
	int y;
	int	x;

	y = data->coo_me[0] - data->coo_you[0];
	x = data->coo_me[1] - data->coo_you[1];
	if ((y - x > 3) || (y - x) < -3)
	{
		if (y > 0)
			data->aim |= UP;
		else
			data->aim |= DOWN;
		if (x > 0)
			data->aim |= LEFT;
		else
			data->aim |= RIGHT;
	}
}

void ft_analyse(t_data *data)
{
	ft_get_first_piece(data);
	// printf("coo me : %d:%d 	| coo you : %d:%d\n", data->coo_me[1], data->coo_me[0], data->coo_you[1], data->coo_you[0]);
	ft_get_aim(data);

}
