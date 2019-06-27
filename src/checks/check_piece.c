/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:23:00 by amamy             #+#    #+#             */
/*   Updated: 2019/06/27 23:04:49 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

/*
** ft_free_piece :
** Free allocations made for data->piece;
*/
static void	ft_free_piece(t_data *data, char **piece)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < data->piece_size[0])
		free(piece[y++]);
	free(piece);
}

/*
** ft_piece_cpy :
** make a copy of data->piece.
*/
static char	**ft_piece_cpy(t_data *data, char **piece)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (!(piece = ft_memalloc(sizeof(char*) * (data->piece_size[0]))))
		return (NULL);
	while (y < data->piece_size[0])
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

/*
** ft_check_block :
** Recursive function which verifies that the shape is in one piece.
*/
static int	ft_check_shape(t_data *data, int y, int x, char **piece)
{
	int		found;

	found = 0;
	if (piece[y][x] == 'F')
		found = 1;
	piece[y][x] = '.';
	if (y > 0 && piece[y - 1][x] == '*' && (found += 1))
		found += ft_check_shape(data, y - 1, x, piece);
	if (piece[y][x] != '\0' && piece[y][x + 1] == '*' && (found += 1))
		found += ft_check_shape(data, y, x + 1, piece);
	if (y < (data->piece_size[0] - 1) && piece[y + 1][x] == '*' && (found += 1))
		found += ft_check_shape(data, y + 1, x, piece);
	if (x > 0 && piece[y][x - 1] == '*' && (found += 1))
		found += ft_check_shape(data, y, x - 1, piece);
	if (found == 0)
		return (0);
	return (found);
}

/*
** ft_check_integrity :
** Forerunner of ft_check_shape. Make a copy of data->piece with ft_piece_cpy,
** find the first star and send the piece copy and star's coordonates to
** ft_check_shape allowint it to do the job;
*/
static int	ft_check_integrity(t_data *data)
{
	int		y;
	int		x;
	char	**piece;

	piece = NULL;
	y = 0;
	if (!(piece = ft_piece_cpy(data, piece)))
		return (-1);
	while (y < data->piece_size[0] + 1)
	{
		x = 0;
		while (data->piece[y][x] != '\0')
		{
			if (data->piece[y][x] == '*')
			{
				piece[y][x] = 'F';
				y = ft_check_shape(data, y, x, piece);
				ft_free_piece(data, piece);
				return (y == data->stars) ? 0 : -1;
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** ft_check_piece:
** CHeck if the cell received match the size given, that it contains only '.'
** and '*', and with ft_check_integrity, that all the stars are next to an other
** star.
*/
int			ft_check_piece(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->stars = 0;
	while (y < data->piece_size[0])
	{
		if ((int)ft_strlen(data->piece[y]) != (data->piece_size[1]))
			return (-1);
		while (data->piece[y][x] != '\0')
		{
			if (data->piece[y][x] != '.' && data->piece[y][x] != '*')
				return (-1);
			if (data->piece[y][x] == '*')
				data->stars++;
			x++;
		}
		x = 0;
		y++;
	}
	if (ft_check_integrity(data) != 0)
		return (-1);
	return (0);
}
