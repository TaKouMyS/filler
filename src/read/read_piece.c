/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 11:02:39 by amamy             #+#    #+#             */
/*   Updated: 2019/06/02 16:33:32 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include "libft.h"

#include <stdio.h>

static void ft_read_piece_size(t_data *data, char *str)
{
	int		i;
	int		i2;
	char	str_piece_size[2][3];

	i = 0;
	i2 = 0;
	ft_bzero(str_piece_size[0], 3);
	ft_bzero(str_piece_size[1], 3);
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

void	ft_read_piece(t_data *data)
{
	int		i;
	char	*str_piece_size;
	i = 0;

	get_next_line(0, &str_piece_size);
	ft_read_piece_size(data, str_piece_size);
	free(str_piece_size);
	while (i < data->piece_size[0])
		get_next_line(0, &data->piece[i++]);
}
