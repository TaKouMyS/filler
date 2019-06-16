/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:41:13 by amamy             #+#    #+#             */
/*   Updated: 2019/06/16 17:43:27 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int	ft_read_map(t_data *data)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < data->map_size[0] + 1)
		get_next_line(0, &data->map[i++]);
	if (ft_check_map(data) == -1)
	{
		ft_putstr("\n\nBad map\n\n");
		return (-1);
	}
	return (0);
}
