/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:26:37 by amamy             #+#    #+#             */
/*   Updated: 2019/07/27 23:10:15 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

/*
** ft_store_token :
** Depending on players number's, store X or O in mathcing variables.
*/

static void	ft_store_token(t_data *data)
{
	if (data->player_number == 1)
	{
		data->tok_me[0] = 'O';
		data->tok_me[1] = 'o';
		data->tok_op[0] = 'X';
		data->tok_op[1] = 'x';
	}
	if (data->player_number == 2)
	{
		data->tok_me[0] = 'X';
		data->tok_me[1] = 'x';
		data->tok_op[0] = 'O';
		data->tok_op[1] = 'o';
	}
}

/*
** ft_read_map_size :
** Given the string written by th VM which specifies the map size, get and store
** the map size in int *data->map_size.
** data->map_size[0] = Y
** data->map_size[1] = X.
*/

static int	ft_read_map_size(char *tmp, t_data *data)
{
	int		i;
	int		i2;
	char	str_map_size[2][4];

	i = 0;
	i2 = 0;
	ft_bzero(str_map_size[0], 3);
	ft_bzero(str_map_size[1], 3);
	while (ft_isdigit(tmp[8 + i]) && str_map_size[0][2] == '\0')
	{
		str_map_size[0][i] = tmp[8 + i];
		i++;
	}
	if (tmp[8 + i++] != ' ')
		return (-1);
	while (ft_isdigit(tmp[8 + i]) && str_map_size[1][2] == '\0')
	{
		str_map_size[1][i2++] = tmp[8 + i];
		i++;
	}
	data->map_size[0] = ft_atoi(str_map_size[0]);
	data->map_size[1] = ft_atoi(str_map_size[1]);
	return (0);
}

/*
** ft_data_mallocation :
** Get memory allocation for most of the structure data (t_data type).
** Execptions : data->coo (in ft_get_player).
*/

static int	ft_data_mallocation(t_data *data, char *map_size)
{
	int i;

	if (!(data->piece_size = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(data->map_size = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(ft_strncmp(map_size, "Plateau ", 8) == 0) \
		|| (ft_read_map_size(map_size, data) == -1))
	{
		ft_memdel((void*)&map_size);
		return (-1);
	}
	if (!(data->piece = ft_memalloc(sizeof(char*) * data->map_size[0])))
		return (-1);
	if (!(data->map = ft_memalloc(sizeof(char*) * (data->map_size[0] + 1))))
		return (-1);
	i = 0;
	while (i < data->map_size[0])
		if (!(data->map[i++] = ft_memalloc(sizeof(char) * (BOARD_W + 1))))
			return (-1);
	if (!(data->hmap = ft_memalloc(sizeof(int*) * (data->map_size[0]))))
		return (-1);
	if (!(data->sq_center = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(data->coo_op = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(data->tok_me = ft_memalloc(sizeof(char) * 2)))
		return (-1);
	if (!(data->tok_op = ft_memalloc(sizeof(char) * 2)))
		return (-1);
	return (0);
}

/*
** ft_get_player :
** Given the strings written by th VM which specifies players number, get and
** store the player's number in int data->player_number.
*/

static int	ft_get_player(t_data *data)
{
	char	*player;

	player = NULL;
	if (!(data->coo = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	dprintf(data->fd2, "%s\n", "<-----------start read-player");
	if (get_next_line(data->fd, &player) != 1)
	{
		dprintf(data->fd2, "GNL error\n");
		ft_memdel((void*)&player);
		return (-1);
	}
	dprintf(data->fd2, "%s\n", player);
	dprintf(data->fd2, "%s\n", "<-----------end read-player");
	if (!(ft_strncmp(player, "$$$ exec p1 : ", 14) == 0 \
		|| ft_strncmp(player, "$$$ exec p2 : ", 14) == 0))
		{
			ft_memdel((void*)&player);
			return (-1);
		}
	if (ft_strstr(player, "p1"))
		data->player_number = 1;
	else if (ft_strstr(player, "p2"))
		data->player_number = 2;
	else
	{
		ft_memdel((void*)&player);
		return (-1);
	}
	ft_memdel((void*)&player);
	return (0);
}

/*
** ft_read :
** Called only on the first iteration of the map.
** Central point of stdout reading.
** Read the first line sent to get player nubmer, save tokens in variables,
** read the map and the piece sent and look for players spawns.
*/

int			ft_read(t_data *data)
{
	char	*map_size;
	int		i;

	i = 0;
	if ((ft_get_player(data) == -1) \
		|| (get_next_line(data->fd, &map_size) != 1) \
		|| (ft_data_mallocation(data, map_size) == -1))
			return (-1);
	ft_store_token(data);
	dprintf(data->fd2, "%s\n", "<-----------start read-map_size - 1");
	dprintf(data->fd2, "%s\n", map_size);
	dprintf(data->fd2, "%s\n", "<-----------end read-map_size - 1 ");
	ft_memdel((void*)&map_size);
	if ((ft_read_map(data) == -1) || (ft_read_piece(data) == -1))
		return (-1);
	ft_get_first_piece(data);
	data->best = BOARD_W;
	return (0);
}
