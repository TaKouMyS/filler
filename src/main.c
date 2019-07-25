/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:03:42 by amamy             #+#    #+#             */
/*   Updated: 2019/07/25 17:17:00 by amamy            ###   ########.fr       */
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
	// char *test = "misc/tests";
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);

	data->fd2 = open(vm, O_WRONLY | O_CREAT, 0644);
	// data->fd = open(test, O_RDONLY);

	data->fd = 0;
	// //ft_putstr("0\n");
	if (ft_read(data) == -1)
	{
		dprintf(data->fd2, "Exit at ft_read in main.c\n");
		return (-1);
	}
	while (1)
	{
		// ft_putstr("1\n");
		if (ft_play(data) == -1)
		{
			dprintf(data->fd2, "Exit at ft_play in main.c\n");
			return (-1);
		}
		 // ft_putstr("2\n");
		if (ft_read_map(data) == -1)
		{
			dprintf(data->fd2, "Read map exit\n");
			return (-1);
		}
		// ft_putstr("3\n");
		if (ft_read_piece(data) == -1)
		{
			dprintf(data->fd2, "Read piece exit\n");
			return (-1);
		}
	}
	if (data->piece)
		ft_free(data);
	else
		free(data);
	dprintf(data->fd2, "Nomal exit\n");
	return(0);
}
