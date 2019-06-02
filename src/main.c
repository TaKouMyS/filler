/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:03:42 by amamy             #+#    #+#             */
/*   Updated: 2019/06/02 19:39:43 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

/*
** ft_free :
** free all remaining allocation for the data structure (t_data).
*/
static void	ft_free(t_data *data)
{
	int i;

	i = 0;
	while (i < data->map_size[0] + 1)
		free(data->map[i++]);
	i = 0;
	free(data->map);
	while (i < data->map_size[0])
		free(data->piece[i++]);
	free(data->map_size);
	free(data->piece);
	free(data->piece_size);
	free(data);

}

int main()
{
	t_data	*data;
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);
	ft_read(data);
	ft_free(data);
	return(0);
}
