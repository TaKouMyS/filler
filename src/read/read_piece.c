/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 11:02:39 by amamy             #+#    #+#             */
/*   Updated: 2019/07/29 15:42:10 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
** ft_read_piece_size :
** Given the strings written by th VM which specifies pieces's size, get and
** store pieces's size in int data->piece_size.
** data->piece_size[0] = Y;
** data->piece_size[1] = X;
*/

static void	ft_read_piece_size(t_data *data, char *str)
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

/*
** ft_read_piece :
** Read standard output to read the piece given by the vm then send it to
** check_map for verification.
*/

int			ft_read_piece(t_data *data)
{
	int		i;
	char	*str_piece_size;
	int		ret;

	i = 0;
	if ((ret = get_next_line(data->fd, &str_piece_size)) != 1)
		return (-1);
	ft_read_piece_size(data, str_piece_size);
	free(str_piece_size);
	while (i < data->piece_size[0])
	{
		if (get_next_line(data->fd, &data->piece[i]) != 1)
			return (-1);
		i++;
	}
	if (ft_check_piece(data) != 0)
		return (-1);
	return (0);
}
