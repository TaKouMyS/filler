/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:32:03 by amamy             #+#    #+#             */
/*   Updated: 2019/07/14 14:57:49 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

#include <stdio.h>

/*
** ft_coo_next_star:
** get coo of next piece's star
*/
int	ft_coo_next_star(t_data *data, int *coo, int first_star)
{
	int	y;
	int	x;

	y = coo[0];
	if (first_star)
	{
		// ft_putstr("first star\n");;
		x = coo[1];
	}
	else
		x = coo[1] + 1;
	while (y < data->piece_size[0])
	{
		while (data->piece[y][x] != '\0')
		{
			if (data->piece[y][x] == '*')
			{
				coo[0] = y;
				coo[1] = x;
				// dprintf(data->fd2, "next _ star Y:X: [%d ; %d]\n", coo[0], coo[1]);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/*
** ft_coo_star_map:
** convert coo of piece to coo on the map
*/
static int	ft_coo_star_map(t_data *data, int *coo_star, int *coo_map)
{
	int	y;
	int	x;

	y = coo_star[1];
	x = coo_star[0];
	coo_map[1] = data->coo[1] + y;
	coo_map[0] = data->coo[0] + x;
	if (coo_map[0] > data->map_size[0] - 1|| coo_map[1] > (data->map_size[1] + 4))
	{
		// printf("if (coo_map[0] > data->map_size[0] || coo_map[1] > data->map_size[1])\nif (%d > %d || %d > %d)", coo_map[0], data->map_size[0], coo_map[1], data->map_size[1]);
		return (-1);
	}
	// printf("coo star map Y:X: [%d ; %d]\n", coo_map[1], coo_map[0]);
	return (0);
}

int	ft_check_play(t_data *data)
{
	int	*coo_star;
	int	*coo_map;
	int	cover;
	int	first_star;

int	i;

i = 1;
	cover = 0;
	first_star = 1;
	if (!(coo_star = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(coo_map = ft_memalloc(sizeof(int) * 2)))
		return (-1);

// dprintf(data->fd2, "\ncoo to check : %d:%d\n", data->coo[0], data->coo[1]);
	while (ft_coo_next_star(data, coo_star, first_star) == 1)
	{
		first_star = 0;
		// dprintf(data->fd2, "\ncoo to check : %d:%d\n", data->coo[0], data->coo[1]);
		if ((ft_coo_star_map(data, coo_star, coo_map) == -1)			\
			|| coo_map[0] < 0 											\
			|| coo_map[0] > (data->map_size[0] - 1) || coo_map[1] < 4	\
			|| coo_map[1] > (data->map_size[1] + 3)		 				\
			|| data->map[coo_map[0]][coo_map[1]] == data->tok_op[0]		\
			|| data->map[coo_map[0]][coo_map[1]] == data->tok_op[1])
			{
				// dprintf(data->fd2, "\nIL EST LA LE RETURN\n");
				return (-1);
			}
			// dprintf(data->fd2, "coomap[0] :%d > %d : data->map_size[0] - 1)\n", coo_map[0], data->map_size[0] - 1);
		if (data->map[coo_map[0]][coo_map[1]] == data->tok_me[0] \
			|| data->map[coo_map[0]][coo_map[1]] == (data->tok_me[1]))
			{

				// dprintf(data->fd2, "coo star map : %d:%d\n", coo_map[0], coo_map[1]);
				cover++;
			}
	}
	if (cover != 1)
	{
		// dprintf(data->fd2, "\nRETURN : cover : %d\n", cover);
		// ft_putstr("coooover\n");
		// printf("<---- end check play \n\n");
		return (-1);
	}
	free(coo_star);
	free(coo_map);
	// printf("<---- end check play \n\n");
	return (0);
}
