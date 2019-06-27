/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:05:34 by amamy             #+#    #+#             */
/*   Updated: 2019/06/27 19:41:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>

// int	ft_check_map(t_data *data)
// {
// 	int	i;
// 	int	i2;
//
// 	i = 0;
// 	i2 = 0;
// 	while (i < data->map_size[0])
// 	{
// 		ft_putstr("fwfwe\n");
// 		printf("data->map[%d] : |%s|\n", i , data->map[i]);
// 		if ((int)ft_strlen(data->map[i]) != (data->map_size[1] + 4))
// 			return (-1);
// 		while (i2 < 3)
// 			if (!(ft_isdigit(data->map[i][i2++])))
// 				return (-1);
// 		if (data->map[i][i2++] != ' ')
// 			return (-1);
// 		while (data->map[i][i2] != '\0')
// 		{
// 			if (data->map[i][i2] != '.' && data->map[i][i2] != 'O'		\
// 				&& data->map[i][i2] != 'o' && data->map[i][i2] != 'X'	\
// 				&& data->map[i][i2] != 'x')
// 					return (-1);
// 			i2++;
// 		}
// 		i++;
// 		i2 = 0;
// 	}
// 	return (0);
// }
