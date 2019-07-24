/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:09:51 by amamy             #+#    #+#             */
/*   Updated: 2019/07/24 15:50:34 by amamy            ###   ########.fr       */
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
	if (number >= 0)
		return (number);
	else
		return (-number);
}

/*
** ft_point_dist :
** Give the distance beetween 2 points on the map.
*/
static int	ft_point_dist(t_data *data, int *coo_map)
{
	int left;
	int right;

	left = ft_abs(data->sq_center[1] - coo_map[1]);
	right = ft_abs(data->sq_center[0] - coo_map[0]);
	return (left - right);
}

int	ft_check_square(t_data *data, int *coo_map)
{
	if (ft_point_dist(data, coo_map) > data->sq_dist)
	{

		return (-1);
	}
	return (0);
}
