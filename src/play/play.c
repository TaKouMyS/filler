/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:29:17 by amamy             #+#    #+#             */
/*   Updated: 2019/07/11 16:24:35 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

// static void	ft_near_star_UL(t_data *data, int y, int x)
// {
// 	char *star;
// 	int i;
//
// 	i = x;
// 	star = NULL;
// 	// printf("datapiece[%d][%d]\n", y, x);
// 	if (data->piece[y][x] != '*')
// 	{
// 		while (y >= 0 && star == NULL)
// 		{
// 			// printf("datapiece[%d]\n", y);
// 			star = ft_strchr(data->piece[y--], '*');
// 		}
// 		y++;
// 		if (star != NULL)
// 		{
// 			while (x >= 0 && data->piece[y][x] != '*')
// 			{
// 				x--;
// 			}
// 		}
// 	}
// 		data->coo[0] = data->coo_me[0] - y;
// 		data->coo[1] = data->coo_me[1] - x;
// }


// static void	ft_go_down(t_data *data)
// static void	ft_go_cut(t_data *data)
// static void	ft_go_fill(t_data *data)


int ft_play(t_data *data)
{
	// ft_putstr("ft_play1\n");
	ft_analyse(data);
	if (data->aim & FILL)
	{
		if (ft_go_fill(data) == -1)
		{
			ft_putstr("ft_go cut -1\n");
			return (-1);
		}
	}
	else if (data->aim & CUT)
	{
		if (ft_go_cut(data) == -1)
		{
			ft_putstr("ft_go cut -1\n");
			return (-1);
		}
	}
	else if (data->aim & UP)
	{
		if (ft_go_up(data) == -1)
		{
			ft_putstr("ft_play -1");
			return (-1);
		}
		// ft_putstr("ft_play3\n");
	}
	else if (data->aim & DOWN)
	{
		if (ft_go_down(data) == -1)
		{
			ft_putstr("ft_go down -1\n");
			return (-1);
		}
	}

	dprintf(data->fd2, "<---------Coup : \n%d %d\n<-----------fin coupe\n", data->coo[0], data->coo[1] - 4);
	ft_putnbr(data->coo[0]);
	ft_putstr(" ");
	ft_putnbr(data->coo[1] - 4);
	ft_putstr("\n");
	return (0);
}
