/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:29:17 by amamy             #+#    #+#             */
/*   Updated: 2019/07/24 18:07:32 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

int ft_make_square(t_data *d)
{
	d->coo[1] = d->sq_center[1] - d->sq_dist - (d->piece_size[1] - 1);
	d->coo[0] = d->sq_center[0] - d->sq_dist - (d->piece_size[0] - 1);
	dprintf(d->fd2, "Next piece : %d:%d\n", d->coo[0], d->coo[1] - 4);
	while (ft_check_play(d) != 0 \
		&& d->coo[0] <= (d->sq_center[0] + d->sq_dist))
		{
			d->coo[1]++;
			if (d->coo[1] >= (d->sq_center[1] + d->sq_dist))
			{
				d->coo[1] = d->sq_center[1] - d->sq_dist
					- (d->piece_size[1] - 1)
						d->coo[0]++;
			}
			dprintf(d->fd2, "Next piece : %d:%d\n", d->coo[0], d->coo[1] - 4);
		}
	return (0);
}
