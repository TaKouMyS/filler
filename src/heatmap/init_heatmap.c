/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:11:23 by amamy             #+#    #+#             */
/*   Updated: 2019/07/27 22:27:38 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

static void	ft_grade(t_data *data, int y, int x, int i)
{
	if ((y > 0 && x > 0 && data->hmap[y - 1][x - 1] == i) \
		|| (y > 0 && data->hmap[y - 1][x] == i) \
		|| (y > 0 && x < BOARD_W - 1 && data->hmap[y - 1][x + 1] == i) \
		|| (x < BOARD_W  - 1 && data->hmap[y][x + 1] == i) \
		|| (y < BOARD_H - 1 && x < BOARD_W - 1 && data->hmap[y + 1][x + 1] == i) \
		|| (y < BOARD_H - 1 && data->hmap[y + 1][x] == i) \
		|| (y < BOARD_H - 1 && x > 0 && data->hmap[y + 1][x - 1] == i) \
		|| (x > 0 && data->hmap[y][x - 1] == i))
		{
			data->hmap[y][x] = i + 1;
		}
}

static void	ft_heat(t_data *data)
{
	int	y;
	int	x;
	int	i;

	x = 0;
	y = 0;
	i = 1;
	while (i < BOARD_W)
	{
		while (y < BOARD_H)
		{
			while (x < BOARD_W)
			{
				if (data->hmap[y][x] == 0)
				ft_grade(data, y, x, i);
				x++;
			}
			x = 0;
			y++;
		}
		x = 0;
		y = 0;
		i++;
	}
}

static void	ft_detect_op(t_data *data, int y, int x)
{
	if ((y > 0 && x > 0 && data->hmap[y - 1][x - 1] == OP) \
		|| (y > 0 && data->hmap[y - 1][x] == OP) \
		|| (y > 0 && x < BOARD_W - 1 && data->hmap[y - 1][x + 1] == OP) \
		|| (x < BOARD_W  - 1 && data->hmap[y][x + 1] == OP) \
		|| (y < BOARD_H - 1 && x < BOARD_W - 1 && data->hmap[y + 1][x + 1] == OP) \
		|| (y < BOARD_H - 1 && data->hmap[y + 1][x] == OP) \
		|| (y < BOARD_H - 1 && x > 0 && data->hmap[y + 1][x - 1] == OP) \
		|| (x > 0 && data->hmap[y][x - 1] == OP))
		{
			data->hmap[y][x] = 1;
		}
}

void	ft_init_heatmap(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < BOARD_H)
	{
		while (x < BOARD_W)
		{
			if (data->hmap[y][x] == 0)
				ft_detect_op(data, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	ft_heat(data);
}
