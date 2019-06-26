/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:11:58 by amamy             #+#    #+#             */
/*   Updated: 2019/06/26 17:50:20 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h

static int ft_star_line(char *line)
{
	int i;
	int	found;

	i = 0;
	found = 0;
	while (line[i] != '*' || line[i] != '\0')
		i++;
	if (line[i] == '*')
		found = 1;
	return (found);
}

static void ft_top_star(t_data *data, int *top_star)
{
	int y;
	int x;

	y = data->coo_me[0]
	x = 0;
	while (data->map[y][x] != '*' && data->map[y][x] != '\0')
		x++;
	if (data->map[y++][x] == '*')
	{
		while (ft_star_line(data->map[y]))
			y++;
		while (data->map[y][x] != '*')
			x++;
		top_star[0] = y;
		top_star[1] = x;
	}
	else

}

void	ft_go_up(t_data *data)
{
	int *top_star;

	if (!(top_star = ft_memalloc(sizeof(int) * 2)))
		return (-1)
	ft_top_star(data, top_star);

}
