/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:28:09 by amamy             #+#    #+#             */
/*   Updated: 2019/06/19 17:32:34 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void ft_get_first_piece(t_data *data, char player)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < data->map_size[0] + 1)
	{
		if (data->map[y][x] == player)
			if (data->player_number == 1)
			{
				data->closest_amamy[0] = y;
				data->closest_amamy[1] = x;
			}
			if (data->player_number == 1)
			{
				data->closest_amamy[0] = y;
				data->closest_amamy[1] = x;
			}

	}
}

void ft_analyse(t_data *data)
{

}
