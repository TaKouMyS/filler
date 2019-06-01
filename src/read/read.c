/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:26:37 by amamy             #+#    #+#             */
/*   Updated: 2019/06/01 17:09:11 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

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


static char **ft_mallocation(int y, int x)
{
	char	**str_read;
	int		i;

	i = 0;
	if (!(str_read = ft_memalloc(sizeof(char*) * y)))
		return (0);
	while (i < y)
		if (!(str_read[i++] = ft_memalloc(sizeof(char) * x)))
			return (0);
	return (str_read);
}

static char	**ft_remallocation(t_data *data, char **str_read)
{
	char	tmp[10][50];
	int		i;

	i = 0;
	if (!(data->map_size = ft_memalloc(sizeof(int) * 2)))
		return (NULL);
	while (i < 10)
	{
		ft_strcpy(tmp[i], str_read[i]);
		free(str_read[i++]);
	}
	free(str_read);
	ft_read_map_size(tmp[9], data);
	printf("y : %d | x : %d\n", data->map_size[0], data->map_size[1]);
	if (!(str_read = ft_mallocation((10 + data->map_size[0] + 1),
		(data->map_size[1] + 4))))
		return (NULL);
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
	if (!(str_read = ft_remallocation(data, str_read)))
		return ;
	i = 0;
	while (i < data->map_size[0])
		free(str_read[i++]);
	free(str_read);
	free(data->map_size);
	free(data);
}
