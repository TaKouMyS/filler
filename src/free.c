/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:09:54 by amamy             #+#    #+#             */
/*   Updated: 2019/07/26 12:25:05 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_free_checks(t_data *data, char **str_read)
{
	int	i;

	(void)data;

	i = 0;
	while (i < 10)
		free(str_read[i++]);
	free(str_read);
}

/*
** ft_free :
** free all remaining allocation for the data structure (t_data).
** Used if everything runned as expected.
*/
void	ft_free(t_data *data)
{
	int i;

	i = 0;
	if (data->map_size)
		while (i < data->map_size[0])
			ft_memdel((void*)&data->map[i++]);
	ft_memdel((void*)&data->map);
	i = 0;
	if (data->piece_size)
		while (i < data->piece_size[0])
			ft_memdel((void*)&data->piece[i++]);
	ft_memdel((void*)&data->map_size);
	ft_memdel((void*)&data->piece);
	ft_memdel((void*)&data->piece_size);
	ft_memdel((void*)&data->sq_center);
	ft_memdel((void*)&data->coo_op);
	ft_memdel((void*)&data->coo);
	ft_memdel((void*)&data->tok_me);
	ft_memdel((void*)&data->tok_op);
	ft_memdel((void*)&data);
}
