/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:11:58 by amamy             #+#    #+#             */
/*   Updated: 2019/07/08 18:27:06 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

static int ft_star_line(char *line, char token)
{
	int i;
	int	found;


	i = 0;
	found = 0;
	if (line == NULL)
	{
		return (-1);
	}
	// printf("######## Start line\n");
	while (!(line[i] == token || line[i] == (token + 32)) && line[i] != '\0')
	{
		i++;
		// printf("SL - Line[%d] : |%c|\n", i, line[i]);
	}
	// printf("######## Stop line\n");
	// printf("line [%d] : |%c|\n", i, line[i]);
	if (line[i] == token || line[i] == (token + 32))
	{
		// ft_putstr("founnd\n");
		found = 1;
	}
	return (found);
}

static int	ft_low_token(t_data *data, int *low_tok)
{
	int y;
	int x;
	int ret;

	y = data->coo[0] + (data->piece_size[0] - 1);
	x = 0;
	ret = 0;
	// printf("0 - Y : %d | x  :%d\n", y ,x);
	while (data->map[y][x] != data->token && data->map[y][x] != '\0')
		x++;
	// printf("1 - Y : %d | x  :%d\n", y ,x);
	if (data->map[y][x] != data->token)
	{
	// printf("2 - Y : %d | x  :%d\n", y ,x);
		while (y > -1 && (!(ret = ft_star_line(data->map[y], data->token)))	\
			&& ret != 1 && ret != -1)
		{
			// printf("2.5 - Y : %d | x  :%d\nSL_ret : %d\n", y ,x, ret);
			y--;
		}
		// printf("3 - Y : %d | x  :%d\n", y ,x);
		if (ret == -1)
		{
			// ft_putstr("-1 low tok\n");
			return (-1);
		}
		x = 0;
		while (y > -1 && data->map[y][x] != '\0'
			&& (!(data->map[y][x] == data->token \
			|| data->map[y][x] == data->token + 32)))
				x++;
	}
	// printf("4 - Y : %d | x  :%d\n", y ,x);
	if (!(data->map[y][x] == data->token \
		|| data->map[y][x] == (data->token + 32)) && y++  == -1)
	{
		while ((ret = ft_star_line(data->map[y], data->token)) == 0 \
			&& ret != -1)
		{
			// printf("5 - Y : %d | x  :%d\nSL_ret : %d\n", y ,x, ret);
			y++;
		}
		if (ret == -1)
		{
			// ft_putstr("-1 low tok\n");
			return (-1);
		}
		x = 0;
		while (data->map[y][x] != data->token && data->map[y][x] != '\0')
			x++;
	}

	low_tok[0] = y;
	low_tok[1] = x;
	// printf("6 - Y : %d | x  :%d\n", y ,x);
	return (0);
}

int	ft_go_down(t_data *data)
{
	int *low_tok;
	int	x0;
	int	ret;

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
	// printf("y : %d | x ; %d\n", data->coo[0], data->coo[1]);
	while ((ret = ft_check_play(data)) != 0)
	{
		// ft_putstr("go dowm - 3\n");
		data->coo[1]--;
		if ((data->coo[1] + (data->piece_size[1] - 1)) < low_tok[1])
		{
			data->coo[1] = x0;
			data->coo[0]--;
		}
		// printf("y : %d | x ; %d\n", data->coo[0], data->coo[1]);
	}
	return (0);
}
