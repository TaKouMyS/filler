/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:09:26 by amamy             #+#    #+#             */
/*   Updated: 2019/07/29 15:40:50 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

/*
** ft_store_first_piece :
** Once ft_get_first_piece got the X and O it will pass coo to this function
** which store them to the matching variable. data->coo for mine, data->coo_op
** for the oponent.
*/

static void	ft_store_first_piece(t_data *data, int tmp[4])
{
	if (data->player_number == 1)
	{
		data->coo[0] = tmp[0] - (data->piece_size[0] - 1);
		data->coo[1] = tmp[1] - (data->piece_size[1] - 1);
		data->coo_op[0] = tmp[2];
		data->coo_op[1] = tmp[3];
	}
	if (data->player_number == 2)
	{
		data->coo[0] = tmp[2] - (data->piece_size[0] - 1);
		data->coo[1] = tmp[3] - (data->piece_size[1] - 1);
		data->coo_op[0] = tmp[0];
		data->coo_op[1] = tmp[1];
	}
}

/*
** ft_get_first_piece :
** Will look for the first X and the first O and store their coordonates.
*/

void		ft_get_first_piece(t_data *data)
{
	int y;
	int x;
	int tmp[4];

	y = 0;
	x = 0;
	while (y < data->map_size[0])
	{
		if (data->map[y][x] == 'O' || data->map[y][x] == 'o')
		{
			tmp[0] = y;
			tmp[1] = x;
		}
		else if (data->map[y][x] == 'X' || data->map[y][x] == 'x')
		{
			tmp[2] = y;
			tmp[3] = x;
		}
		if (data->map[y][x++] == '\0')
		{
			x = 0;
			y++;
		}
	}
	ft_store_first_piece(data, tmp);
}
