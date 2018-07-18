/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placebotleft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:38:40 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/09 13:40:20 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_placebotleft(t_filler *my_filler)
{
	unsigned int	i;
	unsigned int	j;
	int				found;

	i = 1;
	found = 0;
	while (my_filler->valid[i - 1])
	{
		j = 0;
		while (my_filler->valid[0][j])
		{
			if (my_filler->valid[my_filler->mapy - i][j]
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
	my_filler->placex = j;
}
