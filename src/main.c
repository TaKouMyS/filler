/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:03:42 by amamy             #+#    #+#             */
/*   Updated: 2019/07/27 01:18:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>
#include <fcntl.h>

int main()
{

	t_data	*data;

	char *vm = "/Users/amamy/Documents/project/08-filler/git/misc/vm.log";
	char *heat = "/Users/amamy/Documents/project/08-filler/git/misc/heat.log";
	char *test = "misc/tests";
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);

	data->fd2 = open(vm, O_WRONLY | O_CREAT, 0644);
	data->fd_heat = open(heat, O_WRONLY | O_CREAT, 0644);
	data->fd = open(test, O_RDONLY);

	// data->fd = 0;
	if (ft_read(data) == -1)
	{
		dprintf(data->fd2, "Exit at ft_read in main.c\n");
		ft_free(data);
		return (-1);
	}
	while (1)
	{
		// ft_putstr("1\n");
		if (ft_play(data) == -1)
		{
			dprintf(data->fd2, "Exit at ft_play in main.c\n");
			ft_free(data);
			return (-1);
		}
		 // ft_putstr("2\n");
		if (ft_read_map(data) == -1)
		{
			dprintf(data->fd2, "Read map exit\n");
			ft_free(data);
			return (-1);
		}
		// ft_putstr("3\n");
		if (ft_read_piece(data) == -1)
		{
			dprintf(data->fd2, "Read piece exit\n");
			ft_free(data);
			return (-1);
		}
	}
	return(0);
}
