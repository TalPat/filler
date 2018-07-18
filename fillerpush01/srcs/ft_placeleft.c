/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeleft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:10:08 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/04 15:28:01 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_placeleft(t_filler *my_filler)
{
	int	i;
	int	j;
	int found;

	j = 0;
	found = 0;
	while (my_filler->valid[0][j])
	{
		i = 1;
		while (my_filler->valid[i - 1])
		{
			if (my_filler->valid[my_filler->mapy - i][j] == '1')
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
	my_filler->placey = my_filler->mapy - i;
	my_filler->placex = j;
}
