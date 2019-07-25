/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:32:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/25 17:29:30 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

/*
** ft_coo_next_star:
** Get coo of next piece's star.
*/

static int	ft_coo_next_star(t_data *data, int *coo, int first_star)
{
	int	y;
	int	x;

	y = coo[0];
	if (first_star)
		x = coo[1];
	else
		x = coo[1] + 1;
	while (y < data->piece_size[0])
	{
		while (data->piece[y][x] != '\0')
		{
			if (data->piece[y][x] == '*')
			{
				coo[0] = y;
				coo[1] = x;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/*
** ft_coo_star_map:
** Convert coo of piece to coo on the map, according to the coordonates
** stored in data->coo.
*/

static int	ft_coo_star_map(t_data *data, int *coo_star, int *coo_map)
{
	int	y;
	int	x;

	y = coo_star[1];
	x = coo_star[0];
	coo_map[1] = data->coo[1] + y;
	coo_map[0] = data->coo[0] + x;
	if (coo_map[0] > data->map_size[0] - 1 \
		|| coo_map[1] > (data->map_size[1] + 4))
		return (-1);
	return (0);
}

/*
** ft_coo_chk_coup:
** According to coordonates stored in data->coo, get the piece's stars one by
** one and check if this is a valid coup.
*/

static int	ft_chk_coup(t_data *data, int *coo_star, int *coo_map, int mode)
{
	int	cover;
	int	st_star;

	cover = 0;
	st_star = 1;
	while (ft_coo_next_star(data, coo_star, st_star) == 1)
	{
		st_star = 0;
		if ((ft_coo_star_map(data, coo_star, coo_map) == -1)		\
		|| coo_map[0] < 0 || coo_map[0] > (data->map_size[0] - 1)	\
		|| coo_map[1] > (data->map_size[1] + 3) || coo_map[1] < 4	\
		|| data->map[coo_map[0]][coo_map[1]] == data->tok_op[0]		\
		|| data->map[coo_map[0]][coo_map[1]] == data->tok_op[1])
			return (-1);
		if (mode == 0 && (ft_check_square(data, coo_map) == -1))
			return (-1);
		if (data->map[coo_map[0]][coo_map[1]] == data->tok_me[0] 	\
			|| data->map[coo_map[0]][coo_map[1]] == (data->tok_me[1]))
			cover++;
	}
	if (cover != 1)
		return (-1);
	return (0);
}

/*
** ft_check_play:
** Starting point for ft_chk_coup.
** Mode, which is used in ft_chk_coup, will tell if we have to check that the ** coordonate is in the square or not.
*/

int			ft_check_play(t_data *data, int mode)
{
	int	*coo_star;
	int	*coo_map;

	if (!(coo_star = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(coo_map = ft_memalloc(sizeof(int) * 2)))
	{
		free(coo_star);
		return (-1);
	}
	if (ft_chk_coup(data, coo_star, coo_map, mode) == -1)
	{
		free(coo_star);
		free(coo_map);
		return (-1);
	}
	free(coo_star);
	free(coo_map);
	return (0);
}
