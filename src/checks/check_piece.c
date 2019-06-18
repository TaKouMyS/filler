/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:23:00 by amamy             #+#    #+#             */
/*   Updated: 2019/06/18 17:20:32 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

// static int	ft_count_links(t_data *data)
// {
// 	int links;
// 	int	y;
// 	int	x;
//
// 	y = 0;
// 	x = 0;
// 	links = 0;
// 	while(y < data->piece_size[0])
// 	{
// 		while (data->piece[y][x] != '\0')
// 		{
// 			if (data->piece[y][x] == '*')
// 			{
// 				if (y > 0 && data->piece[y - 1][x] == '*')
// 				{
// 						// printf("y -1 = y : %d | x : %d\n", y , x);
// 						links++;
// 				}
// 				if (x > 0 && data->piece[y][x - 1] == '*')
// 				{
// 						// printf("x - 1 = y : %d | x : %d\n", y , x );
// 						links++;
// 				}
// 				if (x < (data->piece_size[1] - 1) && data->piece[y][x + 1])
// 				{
// 					// printf("x + 1 = y : %d | x : %d | data->piece_size[0] : %d\n", y , x, data->piece_size[0]);
// 						links++;
// 				}
// 				// ft_putstr("seg beg\n");
// 				if (y < (data->piece_size[0]  - 1 )&& data->piece[y + 1][x] == '*') // la on va chercher un cran trop loin, probablement pareille au dessus need check
// 				{
// 					// ft_putstr("seg end\n");
// 					// printf("Y + 1 = y : %d | x : %d\n", y , x );
// 						links++;
// 				}
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	return (links);
// }

static void ft_free_piece(t_data *data, char **piece)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while(y < data->piece_size[0])
		free(piece[y++]);
	free(piece);
}

static char **ft_piece_cpy(t_data *data, char **piece)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (!(piece = ft_memalloc(sizeof(char*) * (data->piece_size[0]))))
		return (NULL);
	while(y < data->piece_size[0])
	{
		if (!(piece[y] = ft_memalloc(sizeof(char) * (data->piece_size[1] + 1))))
			return (NULL);
		while (data->piece[y][x] != '\0')
		{
			piece[y][x] = data->piece[y][x];
			x++;
		}
		piece[y][x] = '\0';
		x = 0;
		y++;
	}
	return (piece);
}

	static int	ft_check_block(t_data *data, int y, int x, int dir)
{
	int		found;
	char	**piece;

	piece = NULL;
	printf("y : %d | x : %d | found : %d\n", y , x, found);
	if (!(piece = ft_piece_cpy(data, piece)))
		return (-1);
	found = 0;
	if (dir == 0)
		found  = 1;
	piece[y][x] = '.';
	if (y > 0 && piece[y - 1][x] == '*' && dir != 3 && (found += 1))
		found += ft_check_block(data, y - 1, x, 1);
	if (piece[y][x] != '\0' && piece[y][x + 1] == '*' && dir != 4 \
		&& (found += 1))
			found += ft_check_block(data, y, x + 1, 2);
	if (y < (data->piece_size[0] - 1) && piece[y + 1][x] == '*' \
		&& dir != 1 && (found += 1))
			found += ft_check_block(data, y + 1, x, 3);
	if (x > 0 && piece[y][x - 1] == '*' && dir != 2 && (found += 1))
		found += ft_check_block(data, y, x - 1, 4);
	ft_free_piece(data, piece);
	if (found == 0)
		return (0);
	return (found);
}

static int	ft_check_integrity(t_data *data, int stars)
{
	int	y;
	int	x;

	int to_remove = 0;

	y = 0;
	x = 0;
	while(y < data->piece_size[0] + 1)
	{
		while (data->piece[y][x] != '\0')
		{
			if (data->piece[y][x] == '*')
			{
				if ((to_remove = ft_check_block(data, y, x, 0)) != stars)
				{
					printf("ret : (%d)\n", to_remove);
					return (-1);
				}
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

// static int	ft_check_integrity(t_data *data, int stars)
// {
// 	int links;
//
// 	// links = ft_count_links(data);
// 	printf("links : %d | calc : %d | stars : %d\n", links, ((stars * 2) - 2) , stars);
// 	if (stars > 2 && links < ((stars * 2) - 2))
// 	{
// 		ft_putstr("3");
// 		return (-1);
// 	}
// 	if (stars == 2 && links < 2)
// 	{
// 		ft_putstr("4");
// 		return (-1);
// 	}
// 	return (0);
// }

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
		if ((int)ft_strlen(data->piece[i]) != (data->piece_size[1]))
		{
			ft_putstr("1");
			return (-1);
		}
		while (data->piece[i][i2] != '\0')
		{
			if (data->piece[i][i2] != '.' && data->piece[i][i2] != '*')
					return (-1);
			if (data->piece[i][i2] == '*')
				stars++;
			i2++;
		}
		i++;
		i2 = 0;
	}
	if (ft_check_integrity(data, stars) != 0)
	{
		ft_putstr("2");
		return (-1);
	}
	return (0);
}
