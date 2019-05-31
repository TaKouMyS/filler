/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:26:37 by amamy             #+#    #+#             */
/*   Updated: 2019/05/31 18:46:53 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <stdio.h>

static int	*ft_read_map_size(char *tmp, int *coo)
{
	int		i;
	int		i2;
	char	coo_c[2][4];

	i = 0;
	i2 = 0;
	ft_bzero(coo_c[0], 3);
	ft_bzero(coo_c[1], 3);
	while (ft_isdigit(tmp[8 + i]) && coo_c[0][2] == '\0')
	{
		coo_c[0][i] = tmp[8 + i];
		i++;
	}
	if (tmp[8 + i++] != ' ')
		return (NULL);
	while (ft_isdigit(tmp[8 + i]) && coo_c[1][2] == '\0')
	{
		coo_c[1][i2++] = tmp[8 + i];
		i++;
	}
	coo[0] = ft_atoi(coo_c[0]);
	coo[1] = ft_atoi(coo_c[1]);
	return (coo);
}


static char **ft_mallocation(int y, int x)
{
	char	**str_read;
	int		i;

	i = 0;
	if (!(str_read = ft_memalloc(sizeof(char*) * y)))
		return (0);
	while (i < 10)
		if (!(str_read[i++] = ft_memalloc(sizeof(char) * x)))
			return (0);
	return (str_read);
}

static char	**ft_remallocation(char **str_read)
{
	char	tmp[10][50];
	int		*coo;
	int		i;

	i = 0;
	if (!(coo = ft_memalloc(sizeof(int) * 2)))
		return (NULL);
	while (i < 10)
	{
		ft_strcpy(tmp[i], str_read[i]);
		free(str_read[i++]);
	}
	free(str_read);
	coo = ft_read_map_size(tmp[9], coo);
	printf("y : %d | x : %d\n", coo[0], coo[1]);
	if (!(str_read = ft_mallocation(coo[0], coo[1])))
		return (NULL);
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
	if (!(str_read = ft_mallocation(10, 50)))
		return ;
	gnl_ret = get_next_line(0, &str_read[i++]);
	while (i2++ < 9)
		gnl_ret = get_next_line(0, &str_read[i++]);
	ft_remallocation(str_read);
	// if (!(str_read = ft_memalloc(sizeof(char*) * 10)))
	// 	return ;
	// while (i < 10)
	// 	if (!(str_read[i++] = ft_memalloc(sizeof(char) * 50)))
	// 		return ;
	// ft_putstr("buf :\n");
	// ft_disp_ar(str_read);
	i = 0;
	// while (i < coo[0])
	// 	free(str_read[i++]);
	// free(str_read);
	// free(coo);
}
