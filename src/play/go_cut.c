/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:27:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/07 19:35:18 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

int	ft_go_cut(t_data *data)
{
	data->coo[1] = 0;
		printf("y : %d | x ; %d\n", data->coo[0], data->coo[1]);
		ft_putstr("go dowm\n");
	while ((ft_check_play(data)) != 0)
	{
		ft_putstr("go dowm - 3\n");
		data->coo[1]++;
		if ((data->coo[1] > (data->map_size[1] - 1)))
		{
			data->coo[1] = 0;
			data->coo[0]--;
		}
		printf("y : %d | x ; %d\n", data->coo[0], data->coo[1]);
	}
	return (0);
}
