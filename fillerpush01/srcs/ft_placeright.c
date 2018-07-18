/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeright.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:10:45 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/05 14:44:07 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_placeright(t_filler *my_filler)
{
	int	i;
	int	j;
	int found;

	j = 1;
	found = 0;
	while (my_filler->valid[0][j - 1])
	{
		i = 0;
		while (my_filler->valid[i])
		{
			if (my_filler->valid[i][my_filler->mapx - j] == '1')
			{
				found = 1;
				break ;
			}
			i++;
		}
		if (found)
			break ;
		j++;
	}
	my_filler->placey = i;
	my_filler->placex = my_filler->mapx - j;
}
