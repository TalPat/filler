/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getplayer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:43:25 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/06 11:46:37 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void	ft_getplayer(t_filler *my_filler)
{
	ft_grabline(0, &(my_filler->line));
	my_filler->team = 'O';
	my_filler->enemy = 'X';
	if (ft_strstr(my_filler->line, "p2"))
	{
		my_filler->team = 'X';
		my_filler->enemy = 'O';
	}
	my_filler->gameover = 0;
	my_filler->board = NULL;
	my_filler->cycle = 0;
}
