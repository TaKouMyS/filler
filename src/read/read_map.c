/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:41:13 by amamy             #+#    #+#             */
/*   Updated: 2019/07/07 15:09:05 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

static int	ft_check_map(t_data *data)
{
	int	i;
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

int	ft_read_map(t_data *data)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	if (data->piece_size[0])
	{
		dprintf(data->fd2, "%s\n", "<-----------start map_size");
		get_next_line(data->fd, &data->map[i]);
		// ft_putstr_fd(data->map[i], data->fd2);
		// ft_putstr_fd(" -<PPPP>-\n", data->fd2);
		// dprintf(data->fd2, "%s\n", data->map[i]);
		dprintf(data->fd2, "%s\n", "<-----------end map_size");
	}

	dprintf(data->fd2, "%s\n", "<-----------start solo-line read-map");
	get_next_line(data->fd, &data->map[i]);
	dprintf(data->fd2, "%s\n", data->map[i]);
	dprintf(data->fd2, "%s\n", "<xxxxxxxxxxxend solo-line read-map");
	dprintf(data->fd2, "%s\n", "<-----------start read-map");
	while (i < data->map_size[0])
	{
		get_next_line(data->fd, &data->map[i]);
		dprintf(data->fd2, "%s\n", data->map[i]);
		i++;
	}
	dprintf(data->fd2, "%s\n", "<xxxxxxxxxxx end read-map");
	if (ft_check_map(data) == -1)
	{
		dprintf(data->fd2, "%s\n", "<map error\n");
		ft_putstr("\n\nMap error\n\n");
		return (-1);
	}
	return (0);
}
