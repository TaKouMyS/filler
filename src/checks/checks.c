/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:24:06 by amamy             #+#    #+#             */
/*   Updated: 2019/06/25 15:37:24 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

#include <stdio.h>



// static int	ft_header_checks(char **head)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < 5)
// 		if (ft_strlen(head[i++]) != 48)
// 			return (-1);
// 	if (ft_strncmp(head[0], "# -------------- VM  version ", 29) \
// 		|| ft_strcmp(&head[0][32], " ------------- #"))
// 		return (-1);
// 	return (0);
// }

// int	ft_checks(t_data *data, char **head)
// {
// 	int error;
//
// 	// error = ft_header_checks(head);
// 	error = ft_init_checks(head);
// 	if (error == -1)
// 	{
// 		ft_putstr("\n\n\nBad input\n\n\n");
// 		ft_free_checks(data, head);
// 		return (-1);
// 	}
// 	return (0);
// }
