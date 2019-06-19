/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:23:00 by amamy             #+#    #+#             */
/*   Updated: 2019/06/19 13:12:42 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

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

static int	ft_check_block(t_data *data, int y, int x, char **piece)
{
	int		found;

	found = 0;
	if (piece[y][x] == 'F')
		found = 1;
	piece[y][x] = '.';
	if (y > 0 && piece[y - 1][x] == '*' && (found += 1))
		found += ft_check_block(data, y - 1, x, piece);
	if (piece[y][x] != '\0' && piece[y][x + 1] == '*' && (found += 1))
		found += ft_check_block(data, y, x + 1, piece);
	if (y < (data->piece_size[0] - 1) && piece[y + 1][x] == '*' && (found += 1))
		found += ft_check_block(data, y + 1, x, piece);
	if (x > 0 && piece[y][x - 1] == '*' && (found += 1))
		found += ft_check_block(data, y, x - 1, piece);
	if (found == 0)
		return (0);
	return (found);
}

static int	ft_check_integrity(t_data *data, int stars)
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
				y = ft_check_block(data, y, x, piece);
				ft_free_piece(data, piece);
				return (y == stars) ? 0 : -1;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			ft_check_piece(t_data *data)
{
	int	y;
	int	x;
	int	stars;

	y = 0;
	x = 0;
	stars = 0;
	while (y < data->piece_size[0])
	{
		if ((int)ft_strlen(data->piece[y]) != (data->piece_size[1]))
			return (-1);
		while (data->piece[y][x] != '\0')
		{
			if (data->piece[y][x] != '.' && data->piece[y][x] != '*')
				return (-1);
			if (data->piece[y][x] == '*')
				stars++;
			x++;
		}
		x = 0;
		y++;
	}
	if (ft_check_integrity(data, stars) != 0)
		return (-1);
	return (0);
}
