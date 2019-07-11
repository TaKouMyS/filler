/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:57:31 by amamy             #+#    #+#             */
/*   Updated: 2019/07/11 16:25:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define UP 1
# define DOWN 2
# define CUT 4
# define FILL 8

typedef struct	s_data
{
	int			*map_size;
	char		**map;
	int			*piece_size;
	char		**piece;
	int			player_number;
	char		*tok_me;
	char		*tok_op;
	// int			*coo_me;
	int			*coo_op;
	int			*coo;
	int			stars;
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
int		ft_check_shape(t_data *data, int y, int x, char **piece);
int		ft_play(t_data *data);
void	ft_analyse(t_data *data);
int		ft_go_up(t_data *data);
int		ft_go_down(t_data *data);
int		ft_go_cut(t_data *data);
int		ft_go_fill(t_data *data);
int		ft_star_line(char *line, char token);
int		ft_line_mine(t_data *data, char *line);
int		ft_check_play(t_data *data);

#endif
