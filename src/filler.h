/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:57:31 by amamy             #+#    #+#             */
/*   Updated: 2019/06/25 14:08:40 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define UP 1
# define RIGHT 2
# define DOWN 4
# define LEFT 8

typedef struct	s_data
{
	int			*map_size;
	char		**map;
	int			*piece_size;
	char		**piece;
	int			player_number;
	int			*coo_me;
	int			*coo_you;
	int			*coo;
	int			aim;

	int			fd;
	int			fd2;

}				t_data;

int		ft_read(t_data *data);
void	ft_free(t_data *data);
void	ft_free_checks(t_data *data, char **str_read);
int		ft_read_piece(t_data *data);
int		ft_read_map(t_data *data);
int		ft_check_piece(t_data *data);
int		ft_checks(t_data *data, char **head);
void	ft_play(t_data *data);
void	ft_analyse(t_data *data);

#endif
