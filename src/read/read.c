/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:26:37 by amamy             #+#    #+#             */
/*   Updated: 2019/06/21 16:26:07 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"


#include <stdio.h>

static void ft_free_str_read(char **head, int i)
{
	i--;
	while (i >= 0)
		free(head[i--]);
	free(head);
}

/*
** ft_read_map_size :
** Given the string written by th VM which specifies the map size, get and store
** the map size in int *data->map_size.
** data->map_size[0] = Y
** data->map_size[1] = X.
*/
static void	ft_read_map_size(char *tmp, t_data *data)
{
	int		i;
	int		i2;
	char	str_map_size[2][4];

	i = 0;
	i2 = 0;
	ft_bzero(str_map_size[0], 3);
	ft_bzero(str_map_size[1], 3);
	while (ft_isdigit(tmp[8 + i]) && str_map_size[0][2] == '\0')
	{
		str_map_size[0][i] = tmp[8 + i];
		i++;
	}
	if (tmp[8 + i++] != ' ')
		return ;
	while (ft_isdigit(tmp[8 + i]) && str_map_size[1][2] == '\0')
	{
		str_map_size[1][i2++] = tmp[8 + i];
		i++;
	}
	data->map_size[0] = ft_atoi(str_map_size[0]);
	data->map_size[1] = ft_atoi(str_map_size[1]);
}

/*
** ft_data_mallocation :
** Get memory allocation for most of the structure data (t_data type).
*/
static int	ft_data_mallocation(t_data *data, char *str_read)
{
	if (!(data->piece_size = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(data->map_size = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	ft_read_map_size(str_read, data);
	if (!(data->piece = ft_memalloc(sizeof(char*) * data->map_size[0])))
		return (-1);
	ft_read_map_size(str_read, data);
	if (!(data->map = ft_memalloc(sizeof(char*) * (data->map_size[0] + 1))))
		return (-1);
	if (!(data->coo_me = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(data->coo_you = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(data->coo = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	return (0);
}

/*
** ft_read :
** Central point of stdin reading.
*/
int	ft_read(t_data *data)
{
	char	**head;
	int		gnl_ret;
	int		i;

	i = 0;
	gnl_ret = 1;
	if (!(head = ft_memalloc(sizeof(char*) * 10)))
		return (-1);
	while (i < 10)
		if ((gnl_ret = get_next_line(data->fd, &head[i++])) && gnl_ret == -1)
		{
			ft_free_str_read(head, i);
			return (-1);
		}
	if ((ft_checks(data, head) != 0) \
		|| (ft_data_mallocation(data, head[9]) == -1) \
		|| (ft_read_map(data, head[6], head[8]) == -1) \
		|| (ft_read_piece(data) == -1))
	{
		ft_free_str_read(head, i);
		return (-1);
	}
	ft_free_str_read(head, i);
	return (0);
}
