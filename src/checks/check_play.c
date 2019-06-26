/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:32:03 by amamy             #+#    #+#             */
/*   Updated: 2019/06/26 16:02:17 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

/*
** ft_coo_next_star:
** get coo of next piece's star
*/
int	ft_coo_next_star(t_data *data, int *coo)
{
	int	y;
	int	x;

	y = coo[1];
	x = coo[0];
	while (data->piece[y] < data->piece_size[0])
	{
		while (data->piece[y][x] != '\0')
		{
			if (data->piece[y][x] == '*')
			{
				coo[1] = y;
				coo[0] = x;
				return (1);
			}
			i++;
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
int	*ft_coo_star_map(t_data *data, int *coo_star, int *coo_map)
{
	int	y;
	int	x;

	y = coo_piece[1];
	x = coo_piece[0];
	coo_map[1] = data->coo[1] - y;
	coo_map[0] = data->coo[0] - x;
}

int	ft_check_play(t_data *data)
{
	int	*coo_star;
	int	*coo_map;
	int	cover;

	cover = 0;
	if (!(coo_star = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(coo_map = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	while (ft_next_star(data, coo_star) == 1)
	{
		ft_coo_star_map(data, coo_star, coo_map);
		if (data->map[coo_map[0]][coo_map[1]] == token)
			cover++;
		if (cover > 1)
			return (-1)
	}
	free(coo_star);
	free(coo_map);
	return (0);
}
