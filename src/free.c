/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:09:54 by amamy             #+#    #+#             */
/*   Updated: 2019/06/05 10:56:38 by amamy            ###   ########.fr       */
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
	while (i < data->map_size[0] + 1)
		free(data->map[i++]);
	free(data->map);
	i = 0;
	while (i < data->map_size[0])
		free(data->piece[i++]);
	free(data->map_size);
	free(data->piece);
	free(data->piece_size);
	free(data);
}
