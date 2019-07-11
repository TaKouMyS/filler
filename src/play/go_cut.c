/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:27:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/10 20:19:04 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int	ft_go_cut(t_data *data)
{
	data->coo[0] = data->map_size[0] / 2;
	data->coo[1] = 0;
	while ((ft_check_play(data)) != 0)
	{
		data->coo[1]++;
		if ((data->coo[1] > (data->map_size[1] - 1)))
		{
			data->coo[1] = 0;
			data->coo[0]--;
		}
	}
	return (0);
}
