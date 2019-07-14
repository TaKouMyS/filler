/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:28:09 by amamy             #+#    #+#             */
/*   Updated: 2019/07/13 20:09:19 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

static	void ft_get_aim(t_data *data)
{
	int i;
	int ret;
	int mid;

	i = 0;
	ret = 0;
	mid = data->mid - 3;
	dprintf(data->fd2, "\nGet aim : \ndata->coo[0] : %d\n\n", data->coo[0]);
	if (data->aim & CUT)
	{
		// dprintf(data->fd2, "GO FOR FILL\n");
		while (i <= 5 && (ret = ft_line_mine(data, data->map[mid + i])) != 1)
			i++;
		if (ret == 1)
		{
			data->aim |= FILL;
			dprintf(data->fd2, "***** FILL *****");
		}
	}
	else if(((data->aim & UP && data->coo[0] <= mid)
	|| (data->aim & DOWN && data->coo[0] >= mid))  && !(data->aim & FILL))
	{
		data->aim |= CUT;
		dprintf(data->fd2, "***** CUT *****");
	}
	else if (data->coo[0] > mid && !(data->aim & CUT) && !(data->aim & FILL))
	{
		data->aim |= UP;
		dprintf(data->fd2, "***** UP *****");
	}
	else if (data->coo[0] < mid && !(data->aim & CUT) && !(data->aim & FILL))
	{
		data->aim |= DOWN;
		dprintf(data->fd2, "***** DOWN *****");
	}
}

void ft_analyse(t_data *data)
{
	ft_get_aim(data);
}
