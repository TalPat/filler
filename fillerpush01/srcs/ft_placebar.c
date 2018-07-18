/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placebar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:22:13 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/06 10:07:09 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	ft_placebar(t_filler *my_filler, int gap)
{
	int	i;
	int	j;
	int	found;

	i = gap / 2;
	found = 0;
	while (i < (int)my_filler->mapy && my_filler->valid[i])
	{
		j = -1;
		while (my_filler->valid[i][++j])
			if (my_filler->valid[i][j] == '1')
			{
				found = 1;
				my_filler->placey = i;
				my_filler->placex = j;
				break ;
			}
		if (found)
			break ;
		i += gap;
	}
	if (!found)
		ft_placecycle(my_filler);
}
