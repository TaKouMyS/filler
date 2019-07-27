/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:41:13 by amamy             #+#    #+#             */
/*   Updated: 2019/07/27 22:46:07 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

//** - the first 3 characters are digits and the fourth a space,
static int	ft_check_line_nb(char *str)
{
	int i;

	i = 0;
	while (i < 3)
		if (!(ft_isdigit(str[i++])))
			return (-1);
	if (str[i++] != ' ')
		return (-1);
	return (0);
}

/*
** ft_check_map :
** Will check that the map read and stored is as expected :
** - all lines have the expected number of characters,
** - all following characters are '.', 'X', 'x', 'o, 'O.
*/

static int	ft_check_map(t_data *data, int y)
{
	int	x;

	y = 0;
	x = 0;
	while (y < BOARD_H)
	{
		if ((int)ft_strlen(data->map[y]) != (BOARD_W))
			return (-1);
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] != '.' && data->map[y][x] != 'O'		\
				&& data->map[y][x] != 'o' && data->map[y][x] != 'X'	\
				&& data->map[y][x] != 'x')
				return (-1);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

/*
** ft_read_map :
** Read standard output to read the map given by the vm then send it to
** check_map for verifications.
*/

int			ft_read_map(t_data *data)
{
	int	i;
	char *line;

	i = 0;
	if (data->piece_size[0])
	{
		if (get_next_line(data->fd, &line) != 1)
			return (-1);
		ft_memdel((void*)&line);
	}
	if (get_next_line(data->fd, &line) != 1)
		return (-1);
	ft_memdel((void*)&line);
		dprintf(data->fd2, "%s\n", "<-----------start read-map");
	while (i < data->map_size[0])
	{
		if (get_next_line(data->fd, &line) != 1 || ft_check_line_nb(line) != 0)
			return (-1);
		ft_strcpy(data->map[i], &line[4]);
			dprintf(data->fd2, "%s : %d\n", data->map[i], i);
		i++;
		ft_memdel((void*)&line);
	}
	dprintf(data->fd2, "%s\n", "<-----------end read-map");
	if (ft_check_map(data, i) == -1)
	{
		ft_putstr("\n\nMap error\n\n");
		return (-1);
	}
	return (0);
}

// int			ft_read_map(t_data *data)
// {
// 	int	i;
// 	int	err;
//
// 	i = 0;
// 	err = 0;
// 	if (data->piece_size[0])
// 	{
// 		dprintf(data->fd2, "%s\n", "<-----------start map_size");
// 		if (get_next_line(data->fd, &data->map[i]) != 1)
// 			return (-1);
// 		ft_memdel((void*)&data->map[i]);
// 		dprintf(data->fd2, "%s\n", "<-----------end map_size");
// 	}
// 	dprintf(data->fd2, "%s\n", "<-----------start solo-line read-map");
// 	if (get_next_line(data->fd, &data->map[i]) != 1)
// 		return (-1);
// 	ft_memdel((void*)&data->map[i]);
// 	// dprintf(data->fd2, "%s\n", data->map[i]);
// 	dprintf(data->fd2, "%s\n", "<xxxxxxxxxxxend solo-line read-map");
// 	dprintf(data->fd2, "%s\n", "<-----------start read-map");
// 	dprintf(data->fd_heat, "%s\n", "<-----------start read-map");
// 	while (i < data->map_size[0])
// 	{
// 		if (get_next_line(data->fd, &data->map[i]) != 1)
// 			return (-1);
// 		dprintf(data->fd_heat, "%s\n", data->heatmap[i]);
// 		i++;
// 	}
// 	dprintf(data->fd_heat, "%s\n", "<-----------end read-map");
// 	if (ft_check_map(data, i) == -1)
// 	{
// 		dprintf(data->fd2, "%s\n", "<map error\n");
// 		ft_putstr("\n\nMap error\n\n");
// 		return (-1);
// 	}
// 	return (0);
// }
