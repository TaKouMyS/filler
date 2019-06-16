/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:23:00 by amamy             #+#    #+#             */
/*   Updated: 2019/06/16 17:38:16 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_links(t_data *data, int y, int x, int stars)
{
	int links;

	links = 0;
	if (y > 0)
		if (data->piece[y - 1][x] == '*')
			links++;
	if (x > 0)
		if (data->piece[y][x - 1] == '*')
			links++;
	if (x < data->piece_size[1])
		if (data->piece[y][x + 1] == '*')
			links++;
	if (y < data->piece_size[0])
		if (data->piece[y + 1][x] == '*')
			links++;
	return (links);
}

static int	ft_check_integrity(t_data *data, int y, int x, int stars)
{
	int links;

	links = ft_count_links(data, y, x, stars);
	if (star > 2 && links < ((stars * 2) - 2))
		return (-1);
	if (stars = 2 && links < 2)
		return (-1);
	return (0);
}

int	ft_check_piece(t_data *data)
{

	int	i;
	int	i2;
	int	stars;

	i = 0;
	i2 = 0;
	stars = 0;
	while (i < data->piece_size[0])
	{
		if ((int)ft_strlen(data->piece[i]) != (data->map_size[1]))
			return (-1);
		while (data->piece[i][i2] != '\0')
		{
			if (data->piece[i][i2] != '.' && data->piece[i][i2] != '*')
					return (-1);
			if (data->piece[i][i2] == '*' && stars++ && stars > 0)
				if (ft_check_integrity(data, i, i2, stars) != 0)
					return (-1);
			i2++;
		}
		i++;
		i2 = 0;
	}
	return (0);
}
