/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_cut_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:27:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/12 10:46:48 by amamy            ###   ########.fr       */
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

static void	ft_fill_top(t_data *data)
{
	int	y_save;

	y_save = data->coo[0];
	dprintf(data->fd2, "fill_top\n");
	while ((ft_check_play(data)) != 0)
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
}
static void	ft_fill_bot(t_data *data)
{
	int	y_save;

	y_save = data->coo[0];
		dprintf(data->fd2, "fill_bot\n");
	while ((ft_check_play(data)) != 0)
	{
		dprintf(data->fd2, "BOT - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
		data->coo[1]--;
		if ((data->coo[1] + data->piece_size[1] - 1 <= 0))
		{
			data->coo[1] = data->map_size[1] + 3;
			data->coo[0]++;
		}
		dprintf(data->fd2, "		2 - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
		if (data->coo[0] > data->map_size[0] - 1)
		{
			data->coo[0] = y_save;
			ft_fill_top(data);
		}
	}
}

int	ft_go_fill(t_data *data)
{
	int ret;
	int y;

	dprintf(data->fd2, "ft_go_fill\n");
	ret = 0;
	y = (data->coo_op[0] < data->map_size[0] / 2) ? 0 : data->map_size[0] - 1;
	while ((ret = ft_line_mine(data, data->map[y])) == 0)
	{
		if (data->coo_op[0] > data->map_size[0] / 2)
			y--;
		if (data->coo_op[0] < data->map_size[0] / 2)
			y++;
	}
	data->coo[0] = y;
	data->coo[1] = data->map_size[1] - 3;
	if (data->coo_op[0] < data->map_size[0] / 2)
		ft_fill_top(data);
	if (data->coo_op[0] > data->map_size[0] / 2)
		ft_fill_bot(data);
	return (0);
}

int	ft_go_cut(t_data *data)
{
	data->coo[0] = data->map_size[0] / 2;
	data->coo[1] = 0;
	while ((ft_check_play(data)) != 0)
	{
		data->coo[1]++;
		if ((data->coo[1] > (data->map_size[1] - 1)))
		{
			data->coo[1] = 0;
			data->coo[0]--;
		}
	}
	return (0);
}
