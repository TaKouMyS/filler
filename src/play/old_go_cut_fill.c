/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_go_cut_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:27:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/25 14:07:49 by amamy            ###   ########.fr       */
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
	while ((ft_check_play(data, 1)) != 0 \
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
	if (ft_check_play(data, 0) == -1)
		ft_bruteforce(data);
}
static void	ft_fill_bot(t_data *data)
{
	int	y_save;

	y_save = data->coo[0];
		// dprintf(data->fd2, "fill_bot\n");
	while ((ft_check_play(data, 0)) != 0 && data->coo[0] < data->map_size[0])
	{
		// dprintf(data->fd2, "BOT - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
		data->coo[1]--;
		if ((data->coo[1] + data->piece_size[1] - 1 <= 0))
		{
			data->coo[1] = data->map_size[1] + 3;
			data->coo[0]++;
		}
		// dprintf(data->fd2, "		2 - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
	}
	if (ft_check_play(data, 0) == -1)
		ft_bruteforce(data);
}

int	ft_go_fill(t_data *data)
{
	int ret;
	int y;

	// dprintf(data->fd2, "ft_go_fill\n");
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
static	int	ft_fullest_line(t_data *data)
{
	int	x;
	int	y;
	int	tokens;
	int	best[2];

	y = 0;
	x = 0;
	ft_bzero(best, 2);
	tokens = 0;
	while (y < data->map_size[0])
	{
		if (data->map[y][x] == data->tok_me[0]
			|| data->map[y][x] == data->tok_me[1])
				tokens++;
		if (x++ >= data->map_size[1] - 4)
		{
			if (tokens > best[0])
			{
				best[1] = y;
				best[0] = tokens;
			}
			tokens = 0;
			y++;
		}
	}
	return (best[1]);
}

int	ft_go_cut(t_data *data)
{
	int	y_save;

	y_save = data->coo[0];
	data->coo[1] = -(data->piece_size[1] - 1);
	data->coo[0] = ft_fullest_line(data);
	// dprintf(data->fd2, "ft_go_cut\n");
	dprintf(data->fd2, "go_cut - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
	while ((ft_check_play(data, 0)) != 0	\
		 && data->coo[0] > y_save - 3)
		{
			dprintf(data->fd2, "go_cut - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
			// dprintf(data->fd2, "go_cut - y : %d 	| x : %d\n", data->coo[0], data->coo[1]);
			data->coo[1]++;
			if ((data->coo[1] > (data->map_size[1] - 1)))
			{
				data->coo[1] = -(data->piece_size[1] + 3);;
				data->coo[0]--;
			}
			// if (data->coo[1] >= data->map_size[1] + 4
			// 	&& (data->map[data->coo[0]][data->coo[1]] == data->tok_me[0] \)
			// 	|| data->map[data->coo[0]][data->coo[1]] == data->tok_me[1]) )
			// 	{
			// 		data->coo[1] = -(data->piece_size[1] - 1);
			// 	}
			// if (data->coo[0] < 0)
			// {
			// 	ft_bruteforce(data);
			// }
		}
	return (0);
}
