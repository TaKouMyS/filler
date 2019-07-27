/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:22:15 by amamy             #+#    #+#             */
/*   Updated: 2019/07/27 02:39:30 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
static int	ft_dot_arround(t_data *d, int *coo, int x, int y)
{
	if ((y > 0 && x > 0 && d->heatmap[y - 1][x - 1] == '.') \
		|| (y > 0 && d->heatmap[y - 1][x] == '.') \
		|| (y > 0 && x < d->map_size[1] && d->heatmap[y - 1][x + 1] == '.') \
		|| (x < d->map_size[1] && data->heatmap[y][x + 1] == '.') \
		|| (y < d->map_size[0] && x < d->map_size[1] \
			&& data->heatmap[y + 1][x + 1] == '.') \
		|| (y < d->map_size[0] && data->heatmap[y + 1][x] == '.') \
		|| (y < d->map_size[0] && x > 0 && d->heatmap[y + 1][x - 1] == '.') \
		|| (x > 0 && data->heatmap[y + 1][x] == '.'))
		{
			return
		}
}

static int *ft_get_border(t_data *data, int *coo, int x, int y)
{
	while (data->heatmap[y][x] == data->tok_op[0] \
		|| data->heatmap[y][x] == data->tok_op[0])
			x++;
	if (data->heatmap[y][x] == '\0' || \
		|| data->heatmap[y][x] == data->tok_op[1] \
		|| data->heatmap[y][x] == data->tok_op[1])
		{

		}
}

static void ft_grading(t_data *data, int *coo, int x, int y)
{

}

void ft_heatmap(t_data *data)
{
	int	*coo;
	int	x;
	int	y;

	if (!(coo = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	x = data->coo_op[1];
	y = data->coo_op[0];
	while ()
}
