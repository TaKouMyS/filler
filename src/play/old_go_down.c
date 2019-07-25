/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:11:58 by amamy             #+#    #+#             */
/*   Updated: 2019/07/24 17:49:01 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

static int	ft_low_token(t_data *data, int *low_tok)
{
	int y;
	int x;
	int ret;

	x = data->map_size[1] + 3;
	if ((ret = ft_star_line(data->map[data->mid], data->tok_me[0])))
		y = data->map_size[0] - 1;
	else
		y = data->mid;
	while (y >= 0 && (ret = ft_star_line(data->map[y], data->tok_me[0])) != 1)
		y--;
	if (ret == -1)
		return (-1);
	if (ret == 1)
		while (!(data->map[y][x] == data->tok_me[0] \
			|| data->map[y][x] == data->tok_me[1]) && data->map[y][x] != '\0')
				x--;
	low_tok[0] = y;
	low_tok[1] = x;
	dprintf(data->fd2, "\nLow-token : y:%d	| x:%d\n", y , x);
	return (0);
}
// static int	ft_low_token(t_data *data, int *low_tok)
// {
// 	int y;
// 	int x;
// 	int ret;
//
// 	y = data->coo[0] + (data->piece_size[0] - 1);
// 	x = 0;
// 	ret = 0;
// 	dprintf(data->fd2, "0 - Y : %d | x  :%d\n", y ,x);
// 	while (data->map[y][x] != data->tok_me[0] && data->map[y][x] != '\0' \
// 		&& data->map[y][x] != data->tok_me[1])
// 			x++;
// 	dprintf(data->fd2, "1 - Y : %d | x  :%d\n", y ,x);
// 	if (data->map[y][x] != data->tok_me[0])
// 	{
// 	dprintf(data->fd2, "2 - Y : %d | x  :%d\n", y ,x);
// 		while (y > -1 && (!(ret = ft_star_line(data->map[y], data->tok_me[0])))	\
// 			&& ret != 1 && ret != -1)
// 		{
// 			dprintf(data->fd2, "2.5 - Y : %d | x  :%d\nSL_ret : %d\n", y ,x, ret);
// 			y--;
// 		}
// 		dprintf(data->fd2, "3 - Y : %d | x  :%d\n", y ,x);
// 		if (ret == -1)
// 		{
// 			// ft_putstr("-1 low tok\n");
// 			return (-1);
// 		}
// 		x = 0;
// 		while (y > -1 && data->map[y][x] != '\0'
// 			&& (!(data->map[y][x] == data->tok_me[0] \
// 			|| data->map[y][x] == data->tok_me[1])))
// 				x++;
// 	}
// 	dprintf(data->fd2, "4 - Y : %d | x  :%d\n", y ,x);
// 	if (y < 0)
// 		y = 0;
// 	if ((!(data->map[y][x] == data->tok_me[0] \
// 		|| data->map[y][x] == (data->tok_me[1]))))
// 	{
// 		while ((ret = ft_star_line(data->map[y], data->tok_me[0])) == 0 \
// 			&& ret != -1)
// 		{
// 			dprintf(data->fd2, "5 - Y : %d | x  :%d\nSL_ret : %d\n", y ,x, ret);
// 			y++;
// 		}
// 		if (ret == -1)
// 		{
// 			// ft_putstr("-1 low tok\n");
// 			return (-1);
// 		}
// 		x = 0;
// 		while ((!(data->map[y][x] == data->tok_me[0] \
// 			|| data->map[y][x] == data->tok_me[1])) && data->map[y][x] != '\0')
// 			x++;
// 	}
//
// 	low_tok[0] = y;
// 	low_tok[1] = x;
// 	// dprintf(data->fd2, "6 - Y : %d | x  :%d\n", y ,x);
// 	dprintf(data->fd2, "\nLow-token : y:%d	| x:%d\n", y , x);
// 	return (0);
// }

int	ft_go_down(t_data *data)
{
	int *low_tok;
	int	x0;
	int	ret;

		dprintf(data->fd2, "GO_DOWN\n");
	ret = 0;
	// ft_putstr("go dowm\n");
	if (!(low_tok = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (ft_low_token(data, low_tok) == -1)
	{
		// ft_putstr("low_token -1\n");
		return  (-1);
	}
	// ft_putstr("go dowm - 2\n");
	data->coo[0] = low_tok[0];
	data->coo[1] = low_tok[1];
	x0 = data->coo[1];
	dprintf(data->fd2, "y : %d | x ; %d\n", data->coo[0], data->coo[1]);
	while ((ret = ft_check_play(data, 1)) != 0 && data->coo[0] >= 0)
	{
		data->coo[1]--;
		if ((data->coo[1] + (data->piece_size[1] - 1)) < 0)
		{
			data->coo[1] = x0;
			data->coo[0]--;
		}
		dprintf(data->fd2, "y : %d | x ; %d\n", data->coo[0], data->coo[1]);
	}
	if (ft_check_play(data, 1) == -1)
		ft_bruteforce(data);
	return (0);
}