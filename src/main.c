/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:03:42 by amamy             #+#    #+#             */
/*   Updated: 2019/06/21 16:27:09 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

int main(int argc, char **argv)
{

	t_data	*data;
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);
	//DEBUG
	(void)argc;
	#include <fcntl.h>
	data->fd = open(argv[1], O_RDONLY);
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
