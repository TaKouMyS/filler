/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:57:31 by amamy             #+#    #+#             */
/*   Updated: 2019/07/27 23:24:39 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BOARD_W data->map_size[1]
# define BOARD_H data->map_size[0]
# define ME -1
# define OP -2

# define UP 1
# define DOWN 2
# define CUT 4
# define FILL 8

typedef struct	s_data
{
	int			*map_size;
	char		**map;
	int			**hmap;
	int			*piece_size;
	char		**piece;
	int			player_number;
	char		*tok_me;
	char		*tok_op;
	int			*coo_op;
	int			*coo;
	int 		y;
	int 		x;
	int			stars;
	int			mid;
	int			sq_dist;
	int			*sq_center;
	int			fd;
	int			best;

	int			fd2;
	int			fd_heat;

}				t_data;

int		ft_read(t_data *data);
void 	ft_get_first_piece(t_data *data);
void	ft_free(t_data *data);
void	ft_free_checks(t_data *data, char **str_read);
int		ft_read_piece(t_data *data);
int		ft_read_map(t_data *data);
int		ft_check_piece(t_data *data);
int		ft_check_shape(t_data *data, int y, int x, char **piece);
int		ft_play(t_data *data);
int		ft_check_play(t_data *data, int mode);
int		ft_check_square(t_data *data, int *coo_map);
int		ft_make_heatmap(t_data *data);
void	ft_init_heatmap(t_data *data);

#endif
