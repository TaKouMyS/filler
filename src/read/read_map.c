/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:41:13 by amamy             #+#    #+#             */
/*   Updated: 2019/07/25 17:09:44 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

/*
** ft_check_map :
** Will check that the map read and stored is as expected :
** - all lines have the expected number of characters,
** - the first 3 characters are digits and the fourth a space,
** - all following characters are '.', 'X', 'x', 'o, 'O.
*/

static int	ft_check_map(t_data *data, int i)
{
	int	i2;

	i = 0;
	i2 = 0;
	while (i < data->map_size[0])
	{
		if ((int)ft_strlen(data->map[i]) != (data->map_size[1] + 4))
			return (-1);
		while (i2 < 3)
			if (!(ft_isdigit(data->map[i][i2++])))
				return (-1);
		if (data->map[i][i2++] != ' ')
			return (-1);
		while (data->map[i][i2] != '\0')
		{
			if (data->map[i][i2] != '.' && data->map[i][i2] != 'O'		\
				&& data->map[i][i2] != 'o' && data->map[i][i2] != 'X'	\
				&& data->map[i][i2] != 'x')
				return (-1);
			i2++;
		}
		i++;
		i2 = 0;
	}
	return (0);
}

/*
** ft_read_map :
** Read standard output to read the map given by the vm then send it to
** check_map for verification.
*/

int			ft_read_map(t_data *data)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	if (data->piece_size[0])
	{
		dprintf(data->fd2, "%s\n", "<-----------start map_size");
		if (get_next_line(data->fd, &data->map[i]) != 1)
			return (-1);
		dprintf(data->fd2, "%s\n", "<-----------end map_size");
	}
	dprintf(data->fd2, "%s\n", "<-----------start solo-line read-map");
	if (get_next_line(data->fd, &data->map[i]) != 1)
		return (-1);
	dprintf(data->fd2, "%s\n", data->map[i]);
	dprintf(data->fd2, "%s\n", "<xxxxxxxxxxxend solo-line read-map");
	dprintf(data->fd2, "%s\n", "<-----------start read-map");
	while (i < data->map_size[0])
	{
		if (get_next_line(data->fd, &data->map[i]) != 1)
			return (-1);
		dprintf(data->fd2, "%s\n", data->map[i]);
		i++;
	}
	if (ft_check_map(data, i) == -1)
	{
		dprintf(data->fd2, "%s\n", "<map error\n");
		ft_putstr("\n\nMap error\n\n");
		return (-1);
	}
	return (0);
}
