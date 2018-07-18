/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:11:12 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/09 13:01:18 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdlib.h>

void	ft_getstart(t_filler *my_filler)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (my_filler->board[i])
	{
		j = 0;
		while (my_filler->board[i][j])
		{
			if (my_filler->board[i][j] == my_filler->team)
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found)
			break ;
		i++;
	}
	my_filler->starty = i;
	my_filler->startx = j;
}

void	ft_getmap(t_filler *my_filler)
{
	int	i;

	i = 0;
	ft_grabline(0, &(my_filler->line));
	my_filler->mapy = ft_atoi((my_filler->line) + 8);
	ft_grabline(0, &(my_filler->line));
	my_filler->mapx = ft_strlen(my_filler->line) - 4;
	my_filler->board = (char**)malloc(sizeof(char*) * (my_filler->mapy + 1));
	my_filler->valid = (char**)malloc(sizeof(char*) * (my_filler->mapy + 1));
	(my_filler->board)[my_filler->mapy] = NULL;
	(my_filler->valid)[my_filler->mapy] = NULL;
	ft_grabline(0, &(my_filler->line));
	while (ft_isdigit((my_filler->line)[0]))
	{
		(my_filler->board)[i] = ft_strnew(my_filler->mapx + 1);
		(my_filler->valid)[i] = ft_strnew(my_filler->mapx + 1);
		ft_strcpy((my_filler->board)[i], (my_filler->line) + 4);
		ft_grabline(0, &(my_filler->line));
		i++;
	}
	ft_getstart(my_filler);
}
