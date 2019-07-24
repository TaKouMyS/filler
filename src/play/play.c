/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:29:17 by amamy             #+#    #+#             */
/*   Updated: 2019/07/24 18:26:12 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

// static void	ft_near_star_UL(t_data *data, int y, int x)
// {
// 	char *star;
// 	int i;
//
// 	i = x;
// 	star = NULL;
// 	// printf("datapiece[%d][%d]\n", y, x);
// 	if (data->piece[y][x] != '*')
// 	{
// 		while (y >= 0 && star == NULL)
// 		{
// 			// printf("datapiece[%d]\n", y);
// 			star = ft_strchr(data->piece[y--], '*');
// 		}
// 		y++;
// 		if (star != NULL)
// 		{
// 			while (x >= 0 && data->piece[y][x] != '*')
// 			{
// 				x--;
// 			}
// 		}
// 	}
// 		data->coo[0] = data->coo_me[0] - y;
// 		data->coo[1] = data->coo_me[1] - x;
// }


// static void	ft_go_down(t_data *data)
// static void	ft_go_cut(t_data *data)
// static void	ft_go_fill(t_data *data)


int ft_play(t_data *d)
{
	// dprintf(d->fd2, "sq_dist : %d\ncenter : %d:%d\n", d->sq_dist, d->sq_center[0], d->sq_center[1]);
	d->coo[1] = d->sq_center[1] - d->sq_dist - (d->piece_size[1] - 1);
	d->coo[0] = d->sq_center[0] - d->sq_dist - (d->piece_size[0] - 1);
	// dprintf(d->fd2, "Next piece : %d:%d\n", d->coo[0], d->coo[1] - 4);
	// while (ft_check_play(d, 0) != 0 \
	// 	&& d->coo[0] <= (d->sq_center[0] + d->sq_dist))
	while (ft_check_play(d, 0) != 0 && d->sq_dist < d->map_size[1])
		{
			// dprintf(d->fd2, "We checked : %d:%d\n\n", d->coo[0], d->coo[1] - 4);
			d->coo[1]++;
			if (d->coo[1] > (d->sq_center[1] + d->sq_dist))
			{
				d->coo[1] = d->sq_center[1] - d->sq_dist - (d->piece_size[1]
					- 1);
				d->coo[0]++;
			}
			if (d->coo[0] > (d->sq_center[0] + d->sq_dist))
			{
				d->sq_dist++;
				d->coo[1] = d->sq_center[1] - d->sq_dist - (d->piece_size[1]
					- 1);
				d->coo[0] = d->sq_center[0] - d->sq_dist - (d->piece_size[0]
					- 1);
			}
		// dprintf(d->fd2, "Next piece : %d:%d\n", d->coo[0], d->coo[1] - 4);
		}
	// //ft_putstr("ft_play1\n");

	if (ft_check_play(d, 1) == -1)
		ft_bruteforce(d);
	if (ft_check_play(d, 1) == -1)\
	{
		d->coo[0] = 0;
		d->coo[1] = 4;
	}
	dprintf(d->fd2, "<---------Coup : \n%d %d\n<-----------fin coupe\n", d->coo[0], d->coo[1] - 4);
	ft_putnbr(d->coo[0]);
		ft_putstr(" ");
	ft_putnbr(d->coo[1] - 4);
	ft_putstr("\n");
	return (0);
}
