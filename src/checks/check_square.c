/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:09:51 by amamy             #+#    #+#             */
/*   Updated: 2019/07/24 18:26:31 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

/*
** ft_abs :
** Get the absolute value of an integer.
*/
int static ft_abs(int number)
{

	// dprintf(data->fd2, "1 number : %d\n", number);
	if (number >= 0)
	{
		// dprintf(data->fd2, "2 return  number : %d\n", number);
		return (number);
	}
	else
	{
	// dprintf(data->fd2, "2 return  -number : %d\n", -number);
		return (-number);
	}
}

/*
** ft_point_dist :
** Give the distance beetween 2 points on the map.
*/
static int	ft_point_dist(t_data *data, int *coo_map)
{
	int left;
	int right;

	// dprintf(data->fd2, "coo_map[0] : %d	| coo_map[1] : %d\n", coo_map[0], coo_map[1]);
	left = ft_abs(data->sq_center[1] - coo_map[1]);
	right = ft_abs(data->sq_center[0] - coo_map[0]);
	// dprintf(data->fd2, "left : %d	| right : %d\n left - right : %d\n", left, right, (ft_abs(left + right)));
	return (ft_abs(left + right));
}

int	ft_check_square(t_data *data, int *coo_map)
{
	int res;

	if ((res = ft_point_dist(data, coo_map)) > data->sq_dist)
	{
		return (-1);
	}
	// dprintf(data->fd2, "star's coo : %d:%d 	| res : %d\n", coo_map[0], coo_map[1], res);
	return (0);
}
