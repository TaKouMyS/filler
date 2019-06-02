/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:26:37 by amamy             #+#    #+#             */
/*   Updated: 2019/06/02 16:09:05 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include "libft.h"


#include <stdio.h>

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

static int	ft_data_mallocation(t_data *data, char *str_read)
{
	if (!(data->piece_size = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	if (!(data->map_size = ft_memalloc(sizeof(int) * 2)))
		return (-1);
	ft_read_map_size(str_read, data);
	// printf("map size[0] : %d\n", data->map_size[0]);
	if (!(data->piece = ft_memalloc(sizeof(char*) * data->map_size[0])))
		return (-1);
	ft_read_map_size(str_read, data);
	if (!(data->map = ft_memalloc(sizeof(char*) * (data->map_size[0] + 1))))
		return (-1);
	return (0);
}

void	ft_read(t_data *data)
{
	char	**str_read;
	int		gnl_ret;
	int		i;

	i = 0;
	gnl_ret = 1;
	if (!(str_read = ft_memalloc(sizeof(char*) * 10)))
		return ;
	while (i < 10)
		gnl_ret = get_next_line(0, &str_read[i++]);
	// printf("\nstr_read[9] : |%s|\n", str_read[9]);
	if (ft_data_mallocation(data, str_read[9]) == -1)
		return ;
	ft_read_map(data);
	ft_read_piece(data);
	i = 0;
	while (i < 10)
		free(str_read[i++]);
	free(str_read);
}
