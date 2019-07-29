/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:03:42 by amamy             #+#    #+#             */
/*   Updated: 2019/07/29 15:45:40 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	t_data	*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);
	data->fd = 0;
	if (ft_read(data) == -1)
	{
		ft_free(data);
		return (-1);
	}
	while (1)
		if ((ft_play(data) == -1) || (ft_read_map(data) == -1) \
			|| (ft_read_piece(data) == -1))
		{
			ft_free(data);
			return (-1);
		}
	return (0);
}
