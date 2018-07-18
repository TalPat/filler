/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placebot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:52:59 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/06 08:25:07 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_placebot(t_filler *my_filler)
{
	unsigned int	i;
	unsigned int	j;
	int				found;

	i = 1;
	found = 0;
	while (my_filler->valid[i - 1])
	{
		j = 1;
		while (my_filler->valid[0][j - 1])
		{
			if (my_filler->valid[my_filler->mapy - i][my_filler->mapx - j]
				== '1')
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
	my_filler->placey = my_filler->mapy - i;
	my_filler->placex = my_filler->mapx - j;
}
