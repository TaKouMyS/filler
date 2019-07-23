/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:29:17 by amamy             #+#    #+#             */
/*   Updated: 2019/07/23 20:29:12 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int static ft_abs(int number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

static int	ft_point_dist(t_data *data, int y, int x)
{
	int left;
	int right;

	left = ft_abs(data->center[1] - x);
	right = ft_abs(data->center[0] - y);
	return (left - right);
}

int ft_in_square(t_data *data, int y, int x)
{
	
}
