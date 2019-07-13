/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_cut_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:27:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/13 16:00:41 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

// static int	ft_line_full(char *line)
// {
// 	int i;
//
// 	i = 4;
// 	while (line[i] != '.' && line[i] != '\0')
// 		x++;
// 	if (line[i] == '.')
// 		return (0);
// 	if (line[i] != '.')
// 		return (1);
// 	return (0);
// }

static void	ft_bruteforce(t_data *data)
{
	dprintf(data->fd2, "ft_bruteforce\n");
	data->coo[1] = -(data->piece_size[1] - 1);
	data->coo[0] = 0;
	while ((ft_check_play(data)) != 0)
	{
		data->coo[1]++;
		if (data->coo[1] == data->map_size[1] + 3)
		{
			data->coo[1] = -(data->piece_size[1] - 1);
			data->coo[0]++;
		}
	}

}
static void	ft_fill_top(t_data *data)
{
	int	y_save;

	y_save = data->coo[0];
	dprintf(data->fd2, "fill_top\n");
	while ((ft_check_play(data)) != 0 \
		&& data->coo[0] > data->piece_size[0] - 1)
		{
			data->coo[1]--;
			dprintf(data->fd2, "TOP - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
			if ((data->coo[1] + data->piece_size[1] - 1 <= 0))
			{
				data->coo[1] = data->map_size[1] + 3;
				data->coo[0]--;
			}
			// if (data->coo[0] > data->map_size[0] - 1)
			// {
			// 	data->coo[0] = y_save;
			// 	ft_fill_bot(data);
			// }
			}
	if (ft_check_play(data) == -1)
		ft_bruteforce(data);
}
static void	ft_fill_bot(t_data *data)
{
	int	y_save;

	y_save = data->coo[0];
		dprintf(data->fd2, "fill_bot\n");
	while ((ft_check_play(data)) != 0 && data->coo[0] < data->map_size[0] - 1)
	{
		dprintf(data->fd2, "BOT - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
		data->coo[1]--;
		if ((data->coo[1] + data->piece_size[1] - 1 <= 0))
		{
			data->coo[1] = data->map_size[1] + 3;
			data->coo[0]++;
		}
		dprintf(data->fd2, "		2 - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
	}
	if (ft_check_play(data) == -1)
		ft_bruteforce(data);
}

int	ft_go_fill(t_data *data)
{
	int ret;
	int y;

	dprintf(data->fd2, "ft_go_fill\n");
	ret = 0;
	y = (data->coo_op[0] < data->mid) ? 0 : data->map_size[0] - 1;
	while ((ret = ft_line_mine(data, data->map[y])) == 0)
	{
		if (data->coo_op[0] > data->mid)
			y--;
		if (data->coo_op[0] < data->mid)
			y++;
	}
	data->coo[0] = y;
	data->coo[1] = data->map_size[1] - 3;
	if (data->coo_op[0] < data->mid)
		ft_fill_top(data);
	if (data->coo_op[0] > data->mid)
		ft_fill_bot(data);
	return (0);
}

int	ft_go_cut(t_data *data)
{
	data->coo[0] = data->mid;
	data->coo[1] = -(data->piece_size[1] - 1);
	dprintf(data->fd2, "ft_go_cut\n");
	dprintf(data->fd2, "map_size[1] -1 : %d\n", data->map_size[1] - 1);
	while ((ft_check_play(data)) != 0 \
		&& data->coo[0] > data->piece_size[0] - 1)
		{
			dprintf(data->fd2, "y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
			data->coo[1]++;
			if ((data->coo[1] > (data->map_size[1] - 1)))
			{
				data->coo[1] = -(data->piece_size[1] - 1);;
				data->coo[0]--;
			}
			if (data->coo[0] < 0)
			{
				dprintf(data->fd2, "SHould call random func\n");
				//call random func
				return (-1);
			}
		}
	return (0);
}
