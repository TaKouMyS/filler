/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:29:17 by amamy             #+#    #+#             */
/*   Updated: 2019/07/24 14:42:18 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int ft_make_square(t_data *d)
{
	d->coo[1] = d->sq_center[1] - d->sq_dist - (d->piece_size[1] - 1);
	d->coo[0] = d->sq_center[0] - d->sq_dist - (d->piece_size[0] - 1);
	while (ft_check_play(d) != 0 \
		&& d->coo[0] <= (d->sq_center[0] + d->sq_dist))
		{
			d->coo[1]++;
			if (d->coo[1] > (d->sq_center[1] + d->sq_dist))
			{
				d->coo[1] = d->sq_center[1] - d->sq_dist;
				d->coo[0]++;
			}
		}
	return (0);
}
