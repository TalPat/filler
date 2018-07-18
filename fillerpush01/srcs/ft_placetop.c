/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:46:34 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/03 19:52:46 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_placetop(t_filler *my_filler)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < my_filler->mapy)
	{
		j = 0;
		while (j < my_filler->mapx)
		{
			if (my_filler->valid[i][j] == '1')
				break ;
			j++;
		}
		if (my_filler->valid[i][j] == '1')
			break ;
		i++;
	}
	my_filler->placey = i;
	my_filler->placex = j;
}
