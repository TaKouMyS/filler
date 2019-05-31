/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:26:37 by amamy             #+#    #+#             */
/*   Updated: 2019/05/31 16:00:34 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	*ft_read_map_size(char *str)
{

}

static char **ft_remallocation(char **str_read)
{
	char	tmp[10][50];
	int		coo[2];
	int		i;

	i = 0;
	while (i < 10)
	{
		ft_strncpy(str_read[i], tmp[i])
		free(str_read[i++]);
	}
	free(str_read);
	coo_c = ft_read_map_size()
	i = 0;
	while (ft_isdigit(tmp[9][9 + i]) && coo_c[0][2] == '\0')
		coo_c[0][i] = tmp[9][i++];
	if (tmp[9][9 + i++] != ' ')
		return (NULL);
	while (ft_isdigit(tmp[9][9 + i]) && coo_c[1][2] == '\0')
		coo_c[i] = tmp[9][i++];

}

static char **ft_mallocation()
{
	char **str_read;
	int	i;

	i = 0;
	if (!(str_read = ft_memalloc(sizeof(char*) * 10)))
		return (0);
	while (i < 10)
		if (!(str_read[i++] = ft_memalloc(sizeof(char) * 50)))
			return (0);
	return (str_read);
}

void	ft_read()
{
	char	**str_read;
	int		gnl_ret;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	str_read = ft_mallocation();
	gnl_ret = get_next_line(0, &str_read[i++]);
	while (i2++ < 9)
		gnl_ret = get_next_line(0, &str_read[i++]);
	// if (!(str_read = ft_memalloc(sizeof(char*) * 10)))
	// 	return ;
	// while (i < 10)
	// 	if (!(str_read[i++] = ft_memalloc(sizeof(char) * 50)))
	// 		return ;
	// ft_putstr("buf :\n");
	// ft_disp_ar(str_read);
	i = 0;
	while (i < 10)
		free(str_read[i++]);
	free(str_read);
}
