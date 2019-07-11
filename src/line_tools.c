/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:23:44 by amamy             #+#    #+#             */
/*   Updated: 2019/07/11 13:37:05 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int	ft_line_mine(t_data *data, char *line)
{
	int i;

	i = 4;
	while ((line[i] == data->tok_me[0] || line[i] == data->tok_me[1]) \
		&& line[i] != '\0')
			i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

int	ft_star_line(char *line, char token)
{
	int i;
	int	found;


	i = 0;
	found = 0;
	if (line == NULL)
		return (-1);
	while (!(line[i] == token || line[i] == (token + 32)) && line[i] != '\0')
		i++;
	if (line[i] == token || line[i] == (token + 32))
		found = 1;
	return (found);
}
