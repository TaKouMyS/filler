/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:32:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/29 16:17:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

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
	if (coo_map[0] > BOARD_H - 1 \
		|| coo_map[1] > (BOARD_W))
		return (-1);
	return (0);
}

/*
** ft_check_play3:
** According to coordonates stored in data->coo, get the piece's stars one by
** one and check if this is a valid coup :
** 	- Check if all stars of the piece are on the board or on oponent's piece,
** 	- Check if all stars of the piece aren't on oponent's piece,
** 	- Count stars covering an star already on the board,
**	- Give the heat score of the piece.
*/

static int	ft_check_play3(t_data *data, int *coo_star, int *coo_map, int *best)
{
	int	cover;
	int	st_star;

	st_star = 1;
	cover = 0;
	while (ft_coo_next_star(data, coo_star, st_star) == 1)
	{
		st_star = 0;
		if ((ft_coo_star_map(data, coo_star, coo_map) == -1)		\
		|| coo_map[0] < 0 || coo_map[0] > (BOARD_H - 1)	\
		|| coo_map[1] > (BOARD_W - 1) || coo_map[1] < 0	\
		|| data->map[coo_map[0]][coo_map[1]] == data->tok_op[0]		\
		|| data->map[coo_map[0]][coo_map[1]] == data->tok_op[1])
			return (-1);
		if (data->map[coo_map[0]][coo_map[1]] == data->tok_me[0] 	\
			|| data->map[coo_map[0]][coo_map[1]] == (data->tok_me[1]))
			cover++;
		if (data->hmap[coo_map[0]][coo_map[1]] < *best \
			&& data->hmap[coo_map[0]][coo_map[1]] > 0)
			*best = data->hmap[coo_map[0]][coo_map[1]];
	}
	return (cover);
}

/*
** ft_check_play2:
** Prepare field for ft_check_play3, check the covering stars's number and
** if the piece has a better heatscore, save the coordonates.
*/

static int	ft_check_play2(t_data *data, int *coo_star, int *coo_map)
{
	int *best;
	int cover;

	if (!(best = ft_memalloc(sizeof(int) * 1)))
		return (-1);
	*best = BOARD_W;
	if (((cover = ft_check_play3(data, coo_star, coo_map, best)) == -1) \
		|| (cover != 1))
		{
			ft_memdel((void*)&best);
			return (-1);
		}
	if (*best < data->best)
	{
		data->best = *best;
		data->x = data->coo[1];
		data->y = data->coo[0];
	}
	ft_memdel((void*)&best);
	return (0);
}

/*
** ft_check_play:
** Starting point for the ft_check_play bundle.
*/

int			ft_check_play(t_data *data)
{
	int	*coo_star;
	int	*coo_map;
	int ret;

	if (!(coo_star = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(coo_map = ft_memalloc(sizeof(int) * 2)))
	{
		free(coo_star);
		return (-1);
	}
	if ((ret = ft_check_play2(data, coo_star, coo_map)) == -1)
	{
		free(coo_star);
		free(coo_map);
		return (-1);
	}
	free(coo_star);
	free(coo_map);
	return (ret);
}
