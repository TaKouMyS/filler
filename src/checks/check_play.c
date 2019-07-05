/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:32:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/05 16:46:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

/*
** ft_coo_next_star:
** get coo of next piece's star
*/
int	ft_coo_next_star(t_data *data, int *coo, int first_star)
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
** convert coo of piece to coo on the map
*/
static int	ft_coo_star_map(t_data *data, int *coo_star, int *coo_map)
{
	int	y;
	int	x;

	y = coo_star[1];
	x = coo_star[0];
	coo_map[1] = data->coo[1] - y;
	coo_map[0] = data->coo[0] - x;
	if (coo_map[0] > data->map_size[0] || coo_map[1] > data->map_size[1])
		return (-1);
	return (0);
}

int	ft_check_play(t_data *data)
{
	int	*coo_star;
	int	*coo_map;
	int	cover;
	int	first_star;

	cover = 0;
	first_star = 1;
	if (!(coo_star = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(coo_map = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	while (ft_coo_next_star(data, coo_star, first_star) == 1)
	{
		first_star = 0;
		if (ft_coo_star_map(data, coo_star, coo_map) == -1)
			return (-1);
		if (data->map[coo_map[0]][coo_map[1]] == data->token)
			cover++;
		if (cover != 1)
		{
			ft_putstr("cover\n");
			return (-1);
		}
	}
	free(coo_star);
	free(coo_map);
	return (0);
}
