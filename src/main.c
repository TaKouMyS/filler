/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:03:42 by amamy             #+#    #+#             */
/*   Updated: 2019/06/25 16:28:14 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>
#include <fcntl.h>

int main()
{

	t_data	*data;

	char *vm = "vm.log";

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);

	data->fd2 = open(vm, O_WRONLY | O_CREAT, 0644);

	data->fd = 0;
	if (ft_read(data) == -1)
		return (-1);
	while (1)
	{
		ft_play(data);
		ft_read_map(data);
		ft_read_piece(data);
	}
	if (data->piece)
		ft_free(data);
	else
		free(data);
	return(0);
}
