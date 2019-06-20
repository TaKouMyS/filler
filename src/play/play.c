/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:29:17 by amamy             #+#    #+#             */
/*   Updated: 2019/06/20 18:58:06 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_near_star(t_data *data, int y, int x)
{
	
}

static int	ft_point_dist(int xa, int ya, int xb, int yb)
{
	int ret;

	ret = (xa + ya) - (xb + yb);
	return (ret)
}

void ft_play(t_data *data)
{
	int y;
	int x;

	if (data->aim & UP && data->aim & LEFT)
	{
		ft_near_star(data, data->piece_size[0] - 1, data->piece_size[1] - 1);
	}
	if (data->aim & UP && data->aim & RIGHT)
	{

	}
	if (data->aim & DOWN && data->aim & RIGHT)
	{

	}
	if (data->aim & DOWN && data->aim & LEFT)
	{

	}
}
