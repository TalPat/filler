/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:20:43 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/06 08:48:23 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	ft_setzero(t_filler *my_filler)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < my_filler->mapy)
	{
		j = 0;
		while (j < my_filler->mapx)
		{
			my_filler->valid[i][j] = '0';
			j++;
		}
		i++;
	}
}

static int	ft_validspot(int y, int x, t_filler *my_filler)
{
	unsigned int	i;
	unsigned int	j;
	int				mypiece;

	i = 0;
	mypiece = 0;
	while (i < my_filler->toky)
	{
		j = -1;
		while (++j < my_filler->tokx)
			if ((my_filler->token)[i][j] == '*')
			{
				if ((my_filler->board)[y + i][x + j] == my_filler->enemy ||
				(my_filler->board)[y + i][x + j] ==
				my_filler->enemy - 'A' + 'a')
					return (0);
				if ((my_filler->board)[y + i][x + j] == my_filler->team ||
				(my_filler->board)[y + i][x + j] == my_filler->team - 'A' + 'a')
					mypiece++;
			}
		i++;
	}
	if (mypiece == 1)
		return (1);
	return (0);
}

void		ft_buildvalid(t_filler *my_filler)
{
	unsigned int	i;
	unsigned int	j;

	ft_setzero(my_filler);
	i = 0;
	while (i < (my_filler->mapy - my_filler->toky + 1))
	{
		j = 0;
		while (j < (my_filler->mapx - my_filler->tokx + 1))
		{
			if (ft_validspot(i, j, my_filler))
				(my_filler->valid)[i][j] = '1';
			j++;
		}
		i++;
	}
}
