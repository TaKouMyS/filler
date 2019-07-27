/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:29:17 by amamy             #+#    #+#             */
/*   Updated: 2019/07/27 23:34:57 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

/*
** ft_bruteforce :
** Used in case it not possible to place piece in our square. Will iterate all
** the map from top to find somewehere.
*/

// static void	ft_bruteforce(t_data *data)
// {
// 	dprintf(data->fd2, "ft_bruteforce\n");
// 	data->coo[1] = -(data->piece_size[1] - 1);
// 	data->coo[0] = 0;
// 	while ((ft_check_play(data, 1)) != 0 && data->coo[0] < data->map_size[0])
// 	{
// 		data->coo[1]++;
// 		if (data->coo[1] == data->map_size[1] + 3)
// 		{
// 			data->coo[1] = -(data->piece_size[1] - 1);
// 			data->coo[0]++;
// 		}
// 	}
// }

/*
** ft_thinking :
** Will iterate in the near range of the square to find somewhere to place
** the piece.
*/

// static void	ft_thinking(t_data *d)
// {
// 	d->coo[1] = d->sq_center[1] - d->sq_dist - (d->piece_size[1] - 1);
// 	d->coo[0] = d->sq_center[0] - d->sq_dist - (d->piece_size[0] - 1);
// 	while (ft_check_play(d, 0) != 0 && d->sq_dist < d->map_size[1])
// 	{
// 		d->coo[1]++;
// 		if (d->coo[1] > (d->sq_center[1] + d->sq_dist))
// 		{
// 			d->coo[1] = d->sq_center[1] - d->sq_dist - (d->piece_size[1]
// 				- 1);
// 			d->coo[0]++;
// 		}
// 		if (d->coo[0] > (d->sq_center[0] + d->sq_dist))
// 		{
// 			d->sq_dist++;
// 			d->coo[1] = d->sq_center[1] - d->sq_dist - (d->piece_size[1]
// 				- 1);
// 			d->coo[0] = d->sq_center[0] - d->sq_dist - (d->piece_size[0]
// 				- 1);
// 		}
// 	}
// }

static void	ft_view_hmap(t_data *data)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while ( y < BOARD_H)
	{
		while (x < BOARD_W)
		{
			dprintf(data->fd_heat, "|%d", data->hmap[y][x++]);
		}
		x = 0;
		y++;
		dprintf(data->fd_heat, "|\n");
	}
	dprintf(data->fd_heat, "\n");
}
static void	ft_thinking2(t_data *data)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (data->coo[0] < BOARD_H)
	{
		while (data->coo[1] < BOARD_W)
		{
			if ((y = ft_check_play(data, 1)) == 1)
			{
				data->x = data->coo[1];
				data->y = data->coo[0];
			}
			dprintf(data->fd2, "ret = %d\nY:X | %d:%d\n", y, data->coo[0], data->coo[1]);
			data->coo[1]++;
		}
		data->coo[1] = 0;
		data->coo[0]++;
	}
}

/*
** ft_play :
** If thinking ha failed to find somewhere.
*/
int			ft_play(t_data *data)
{
	int i;

	// ft_thinking(data);
	ft_make_heatmap(data);
	ft_init_heatmap(data);
	ft_view_hmap(data);
	ft_thinking2(data);
	dprintf(data->fd2, "y:x | %d:%d\n", data->coo[0], data->coo[1]);
	// if (ft_check_play(data, 1) == -1)
	// 	ft_bruteforce(data);
	// if (ft_check_play(data, 1) == -1)\
	// {
	// 	data->coo[0] = 0;
	// 	data->coo[1] = 0;
	// }
	ft_putnbr(data->y);
	ft_putstr(" ");
	ft_putnbr(data->x);
	ft_putstr("\n");

	i = 0;
	while (i < data->piece_size[0])
		ft_memdel((void*)&data->piece[i++]);
	return (0);
}
