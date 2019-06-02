/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:57:31 by amamy             #+#    #+#             */
/*   Updated: 2019/06/02 15:30:45 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct	s_data
{
	int			*map_size;
	char		**map;
	int			*piece_size;
	char		**piece;

}				t_data;

void	ft_read(t_data *data);
void	ft_read_piece(t_data *data);
void	ft_read_map(t_data *data);

#endif
