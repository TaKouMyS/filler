/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:26:37 by amamy             #+#    #+#             */
/*   Updated: 2019/05/30 14:41:37 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	ft_read()
{
	char	*str_read;
	char	*buf;
	char	*tmp;
	int		gnl_ret;

	if (!(str_read = ft_memalloc(sizeof(char) * 100)))
		return ;
	if (!(buf = ft_memalloc(sizeof(char) * 1)))
		return ;
	gnl_ret = get_next_line(0, &str_read);
	while (gnl_ret > 0)
	{
		if (!(tmp = ft_strjoin(buf, "\n")))
			return ;
		free(buf);
		if (!(buf = ft_strjoin(tmp, str_read)))
			return ;
		free(tmp);
		gnl_ret = get_next_line(0, &str_read);
	}
	ft_putstr(buf);
}
