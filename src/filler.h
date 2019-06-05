/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:57:31 by amamy             #+#    #+#             */
/*   Updated: 2019/06/05 11:51:12 by amamy            ###   ########.fr       */
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
	int			player_number;

}				t_data;

int		ft_read(t_data *data);
void	ft_free(t_data *data);
void	ft_free_checks(t_data *data, char **str_read);
void	ft_read_piece(t_data *data);
int		ft_read_map(t_data *data);
int		ft_check_map(t_data *data);
int		ft_checks(t_data *data, char **head);

#endif
