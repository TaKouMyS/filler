/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:41:13 by amamy             #+#    #+#             */
/*   Updated: 2019/06/21 16:24:04 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>


/*
** ft_get_player :
** Given the strings written by th VM which specifies players number, get and ** store the player's number in int data->player_number.
*/
static int	ft_get_player(t_data *data, char* str_p1, char *str_p2)
{
	if (ft_strstr(str_p1, "amamy"))
		data->player_number = 1;
	else if (ft_strstr(str_p2, "amamy"))
		data->player_number = 2;
	else
		return (-1);
	return (0);

}

int	ft_read_map(t_data *data, char* str_p1, char *str_p2)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < data->map_size[0] + 1)
		get_next_line(data->fd, &data->map[i++]);
	if (ft_check_map(data) == -1)
	{
		ft_putstr("\n\nMap error\n\n");
		return (-1);
	}
	if (ft_get_player(data, str_p1, str_p2) == -1)
	{
		ft_putstr("\n\nPlayer error\n\n");
		return (-1);
	}
	return (0);
}
