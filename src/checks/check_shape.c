/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:18:00 by amamy             #+#    #+#             */
/*   Updated: 2019/07/24 15:11:52 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

static int	ft_next(t_data *data, int y, int x, char **piece)
{
	int found;

	found = 0;
	if (piece[y][x] != '\0' && y < (data->piece_size[0] - 1) \
		&& piece[y + 1][x + 1] == '*' && (found += 1))
			found += ft_check_shape(data, y + 1, x + 1, piece);
	if (y < (data->piece_size[0] - 1) && piece[y + 1][x] == '*' && (found += 1))
	{
		found += ft_check_shape(data, y + 1, x, piece);
	}
	if (y < (data->piece_size[0] - 1) && x > 0 && piece[y + 1][x - 1] == '*' \
		&& (found += 1))
	{
			found += ft_check_shape(data, y + 1, x - 1, piece);
	}
	if (x > 0 && piece[y][x - 1] == '*' && (found += 1))
	{
		found += ft_check_shape(data, y, x - 1, piece);
	}
	if (x > 0 && y > 0 \
		&& piece[y - 1][x - 1] == '*' && (found += 1))
	{
		found += ft_check_shape(data, y - 1, x - 1, piece);
	}
	return (found);
}

/*
** ft_check_shape :
** Recursive function which verifies that the shape is in one piece.
*/
int	ft_check_shape(t_data *data, int y, int x, char **piece)
{
	int		found;

	dprintf(data->fd2, "coo (Y:X) : %d:%d\n", y, x);
	found = 0;
	if (piece[y][x] == 'F')
		found = 1;
	piece[y][x] = '.';
	if (y > 0 && piece[y - 1][x] == '*' &&(found += 1))
	{
		found += ft_check_shape(data, y - 1, x, piece);
	}
	if (y > 0 && piece[y][x] != '\0' && piece[y - 1][x + 1] == '*' \
		&& (found += 1))
	{
			found += ft_check_shape(data, y - 1, x + 1, piece);
	}
	if (piece[y][x] != '\0' && piece[y][x + 1] == '*' && (found += 1))
	{
		found += ft_check_shape(data, y, x + 1, piece);
	}
	found += ft_next(data, y, x, piece);
	if (found == 0)
		return (0);
	return (found);
}
