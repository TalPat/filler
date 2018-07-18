/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placevbar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 09:01:24 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/06 11:31:12 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	ft_placevbar(t_filler *my_filler, int gap)
{
	int	i;
	int	j;
	int	found;

	j = gap / 2;
	found = 0;
	while (j < (int)my_filler->mapx)
	{
		i = -1;
		while (my_filler->valid[++i])
			if (my_filler->valid[i][j] == '1')
			{
				found = 1;
				my_filler->placey = i;
				my_filler->placex = j;
				break ;
			}
		if (found)
			break ;
		j += gap;
	}
	if (!found)
		ft_placebar(my_filler, my_filler->mapy / 4);
}
