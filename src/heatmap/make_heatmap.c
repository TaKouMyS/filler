/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:17:29 by amamy             #+#    #+#             */
/*   Updated: 2019/07/29 16:06:27 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
** ft_make_heatmap :
** Read for classique map and make an other :
** '.' Becomes 0
** I Becomes -1
** Oponent's Becomes -2
*/

int	ft_make_heatmap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < BOARD_H)
	{
		if (!(data->hmap[y] = ft_memalloc(sizeof(int) * BOARD_W)))
			return (-1);
		while (x < BOARD_W)
		{
			if (data->map[y][x] == '.')
				data->hmap[y][x] = 0;
			if (data->map[y][x] == data->tok_me[0] \
				|| data->map[y][x] == data->tok_me[1])
				data->hmap[y][x] = -1;
			if (data->map[y][x] == data->tok_op[0] \
				|| data->map[y][x] == data->tok_op[1])
				data->hmap[y][x] = -2;
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
