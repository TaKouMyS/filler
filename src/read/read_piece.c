/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 11:02:39 by amamy             #+#    #+#             */
/*   Updated: 2019/07/07 15:30:49 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

/*
** ft_read_piece_size :
** Given the strings written by th VM which specifies pieces's size, get and
** store pieces's size in int data->piece_size.
** data->piece_size[0] = Y;
** data->piece_size[1] = X;
*/
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

int	ft_read_piece(t_data *data)
{
	int		i;
	char	*str_piece_size;
	i = 0;

	// if (!(str_piece_size = ft_memalloc(sizeof(char) * (30))))
	// 	return (-1);
	int ret;
	if ((ret = get_next_line(data->fd, &str_piece_size)) == -1)
			return (-1);
	if (ret == 0)
		return (0);

			ft_putstr_fd("ici\n", data->fd2);
			// ft_putstr("ici\n");
		dprintf(data->fd2, "%s\n", "<-----------start piece size");
			// ft_putstr_fd("la\n", data->fd2);
			// ft_putstr("la\n");
		dprintf(data->fd2, "%s\n", str_piece_size); //Use of uninitialised value of size 8 && Invalid read of size 1
		// dprintf(data->fd2, "%s\n", str_piece_size); //Use of uninitialised value of size 8 && Invalid read of size 1
			// ft_putstr_fd("la_bas\n", data->fd2);
			// ft_putstr("la_bas\n");
		dprintf(data->fd2, "%s\n", "<-----------end piece size");
			// ft_putstr_fd("kiki\n", data->fd2);
			//  ft_putstr("kiki\n");
	ft_read_piece_size(data, str_piece_size);
	free(str_piece_size);
		dprintf(data->fd2, "%s\n", "<-----------strart read-piece");
	while (i < data->piece_size[0])
	{
		get_next_line(data->fd, &data->piece[i]);
		dprintf(data->fd2, "%s\n", data->piece[i]);
		// dprintf(data->fd2, "test\n");
		i++;
	}
		dprintf(data->fd2, "%s\n", "<-----------end read-piece-->");
		if (ft_check_piece(data) != 0)
	{
		ft_putstr("\n\nPiece error.\n\n");
		return (-1);
	}
	return (0);
}
