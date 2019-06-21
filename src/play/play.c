/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:29:17 by amamy             #+#    #+#             */
/*   Updated: 2019/06/21 16:06:21 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

static void	ft_near_star_UL(t_data *data, int y, int x)
{
	char *star;
	int i;

	i = x;
	if (data->piece[y][x] != '*')
	{
		while (y >= 0 && star == NULL)
		{
			star = ft_strchr(data->piece[y--], '*');
		}
		y++;
		if (star != NULL)
		{
			while (x >= 0 && data->piece[y][x] != '*')
			{
				x--;
			}
		}
	}
		data->coo[0] = data->coo_me[0] - y;
		data->coo[1] = data->coo_me[1] - x;

}

// static int	ft_point_dist(int xa, int ya, int xb, int yb)
// {
// 	int ret;
//
// 	ret = (xa + ya) - (xb + yb);
// 	return (ret);
// }

void ft_play(t_data *data)
{
	ft_analyse(data);
	if (data->aim & UP && data->aim & LEFT)
	{
		ft_near_star_UL(data, data->piece_size[0] - 1, data->piece_size[1] - 1);
		ft_putnbr(data->coo[0]);
		ft_putstr(" ");
		ft_putnbr(data->coo[1]);
		ft_putstr("\n");
	}
	// if (data->aim & UP && data->aim & RIGHT)
	// {
	//
	// }
	// if (data->aim & DOWN && data->aim & RIGHT)
	// {
	//
	// }
	// if (data->aim & DOWN && data->aim & LEFT)
	// {
	//
	// }
}
