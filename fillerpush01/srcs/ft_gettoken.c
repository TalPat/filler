/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettoken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:08:39 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/06 08:49:22 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void		ft_gettoken(t_filler *my_filler)
{
	unsigned int	i;

	i = 0;
	my_filler->toky = ft_atoi((my_filler->line) + 6);
	ft_grabline(0, &(my_filler->line));
	my_filler->tokx = ft_strlen(my_filler->line);
	my_filler->token = (char**)malloc(sizeof(char*) * (my_filler->toky + 1));
	(my_filler->token)[my_filler->toky] = NULL;
	while (i < my_filler->toky - 1)
	{
		(my_filler->token)[i] = strdup(my_filler->line);
		ft_grabline(0, &(my_filler->line));
		i++;
	}
	(my_filler->token)[i] = strdup(my_filler->line);
}
