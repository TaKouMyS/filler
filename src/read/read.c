/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:26:37 by amamy             #+#    #+#             */
/*   Updated: 2019/06/01 21:24:35 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <stdio.h>

static void ft_read_piece_size(t_data *data)
{
	int		i;
	int		i2;
	char 	*str;
	char	str_piece_size[2][3];

	i = 0;
	i2 = 0;
	str = NULL;
	ft_bzero(str_piece_size[0], 3);
	ft_bzero(str_piece_size[1], 3);
	get_next_line(0, &str);
	while (ft_isdigit(str[6 + i]) && str_piece_size[0][1] == '\0')
	{
		str_piece_size[0][i] = str[6 + i];
		i++;
	}
	if (str[6 + i++] != ' ')
		return ;
	while (ft_isdigit(str[6 + i]) && str_piece_size[1][1] == '\0')
	{
		str_piece_size[1][i2++] = str[6 + i];
		i++;
	}
	data->piece_size[0] = ft_atoi(str_piece_size[0]);
	data->piece_size[1] = ft_atoi(str_piece_size[1]);
}

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


static char **ft_mallocation(int y, int x)
{
	char	**str_read;
	int		i;

	i = 0;
	if (!(str_read = ft_memalloc(sizeof(char*) * y)))
		return (0);
	while (i < y)
		if (!(str_read[i++] = ft_memalloc(sizeof(char) * (x + 1))))
			return (0);
	return (str_read);
}

static void	ft_read_piece(t_data *data)
{
	int		i;

	i = 0;
	if (!(data->piece_size = ft_memalloc(sizeof(int) * 2)))
		return ;
	ft_read_piece_size(data);
	if (!(data->piece = ft_mallocation((data->piece_size[0]),
		(data->piece_size[1]))))
			return ;
	while (i < data->piece_size[0])
		get_next_line(0, &data->piece[i++]);
	ft_putstr("\npiece : \n");
	ft_disp_ar(data->piece);
}

static char	**ft_read_map(t_data *data, char **str_read)
{
	int		i;

	i = 0;
	if (!(data->map_size = ft_memalloc(sizeof(int) * 2)))
		return (NULL);
	ft_read_map_size(str_read[9], data);
	while (i < 10)
		free(str_read[i++]);
	free(str_read);
	if (!(data->map = ft_mallocation((data->map_size[0]),
		(data->map_size[1] + 4))))
			return (NULL);
	i = 0;
	while (i < data->map_size[0] + 1)
		get_next_line(0, &data->map[i++]);
	return (str_read);
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
	ft_read_map(data, str_read);
	ft_read_piece(data);
	// if (!(str_read = ft_remallocation(data, str_read)))
	// 	return ;
	i = 0;
	// while (i < data->map_size[0])
	// 	free(str_read[i++]);
	// free(str_read);
	free(data->map_size);
	free(data);
}
