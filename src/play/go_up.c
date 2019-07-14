/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:11:58 by amamy             #+#    #+#             */
/*   Updated: 2019/07/14 14:53:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

static int	ft_top_token(t_data *data, int *top_tok)
{
	int y;
	int x;
	int ret;

	y = data->coo[0];
	x = 0;
	ret = 0;
	while (data->map[y][x] != '\0' && (!(data->map[y][x] == data->tok_me[0] \
		&& data->map[y][x] == data->tok_me[1])))
		x++;
	if (data->map[y][x] != data->tok_me[0] \
		&& data->map[y][x] != data->tok_me[1])
	{
		while ((!(ret = ft_star_line(data->map[y], data->tok_me[0]))) \
			&& ret != 1 && ret != -1)
			y++;
		if (ret == -1)
			return (-1);
		x = 0;
		while (data->map[y][x] != data->tok_me[0] \
			&& data->map[y][x] != data->tok_me[1])
			x++;
	}
	top_tok[0] = y;
	top_tok[1] = x;
	return (0);
}

int	ft_go_up(t_data *data)
{
	int *top_tok;
	int	x0;
	int	ret;

		dprintf(data->fd2, "GO_UP\n");
	ret = 0;
	if (!(top_tok = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	// ft_putstr("go_up1\n");
	if (ft_top_token(data, top_tok) == -1)
	{
		dprintf(data->fd2, "return -1 top tok\n");
		return  (-1);
	}
	// ft_putstr("go_up2\n");
	data->coo[0] = top_tok[0] - (data->piece_size[0] - 1);
	data->coo[1] = top_tok[1] - (data->piece_size[1] - 1);
	x0 = data->coo[1];
	// ft_putstr("wertyui -1\n");
	while ((ret = ft_check_play(data)) != 0 \
		&& data->coo[0] < data->map_size[0] - 1)
		{
			// dprintf(data->fd2, "Go up - while check play\n");
			data->coo[1]++;
			if (data->coo[1] > top_tok[1])
			{
				data->coo[1] = x0;
				data->coo[0]++;
			}
		}
	if (ft_check_play(data) == -1)
		ft_bruteforce(data);
	// dprintf(data->fd2, "return 0 go up\n");
	return (0);
}
