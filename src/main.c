/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:03:42 by amamy             #+#    #+#             */
/*   Updated: 2019/06/24 19:05:49 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

int main()
{

	t_data	*data;
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);
	//DEBUG
	// char *file = "tests";
	#include <fcntl.h>
	// if ((data->fd = open(file, O_RDONLY) == -1))
	// 	return (-1);
	data->fd = 0;
	//
	if (ft_read(data) == -1)
		return (-1);
	ft_play(data);
	if (data->piece)
		ft_free(data);
	else
		free(data);
	return(0);
}
