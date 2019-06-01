/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:57:31 by amamy             #+#    #+#             */
/*   Updated: 2019/06/01 12:39:28 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include <stdlib.h>
# include <libft.h>

typedef struct	s_data
{
	int			*map_size;
}				t_data;

void	ft_read(t_data *data);

#endif
