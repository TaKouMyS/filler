/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:11:58 by amamy             #+#    #+#             */
/*   Updated: 2019/07/09 17:38:39 by amamy            ###   ########.fr       */
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
	// ft_putstr("star_line\n");
	// printf("line : |%s|\n", line);
	// printf("token : %c\n", token);
	if (line == NULL)
	{
		// ft_putstr("ft_star_line -1");
		return (-1);
	}
	while (!(line[i] == token || line[i] == (token + 32)) && line[i] != '\0')
	{
		// printf("line[%d] : %c\n", i, line[i]);
		i++;
	}
	if (line[i] == token || line[i] == (token + 32))
	{
		// printf("found\n");
		found = 1;
	}
		// ft_putstr("star_line2\n");
	return (found);
}

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

	ret = 0;
	if (!(top_tok = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	// ft_putstr("go_up1\n");
	if (ft_top_token(data, top_tok) == -1)
	{
		ft_putstr("ft_go_up -1\n");
		return  (-1);
	}
	// ft_putstr("go_up2\n");
	data->coo[0] = top_tok[0] - (data->piece_size[0] - 1);
	data->coo[1] = top_tok[1] - (data->piece_size[1] - 1);
	x0 = data->coo[1];
	// ft_putstr("wertyui -1\n");
	while ((ret = ft_check_play(data)) != 0)
	{
		// printf("ret : |%d|\n", ret);
		// if (ret == -1)
		// {
		// 	ft_putstr("ft_go_up -1\n");
		// 	return (-1);
		// }
		// ft_putstr("go_up3\n");
		data->coo[1]++;
		if (data->coo[1] > top_tok[1])
		{
			data->coo[1] = x0;
			data->coo[0]++;
		}
	}
	// ft_putstr("wertyui -3\n");
	return (0);
}
