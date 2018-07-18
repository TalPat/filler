/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placecross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:40:38 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/06 13:19:58 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		ft_placehcross(t_filler *my_filler)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (my_filler->valid[i])
	{
		if (my_filler->valid[i][my_filler->startx] == '1')
		{
			found = 1;
			break ;
		}
		i++;
	}
	my_filler->placey = i;
	my_filler->placex = my_filler->startx;
	return (found);
}

int		ft_placevcross(t_filler *my_filler)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (my_filler->valid[0][i])
	{
		if (my_filler->valid[my_filler->starty][i] == '1')
		{
			found = 1;
			break ;
		}
		i++;
	}
	my_filler->placex = i;
	my_filler->placey = my_filler->starty;
	return (found);
}

void	ft_placecross(t_filler *my_filler)
{
	if (!ft_placevcross(my_filler))
		if (!ft_placehcross(my_filler))
			ft_placecycle(my_filler);
}
