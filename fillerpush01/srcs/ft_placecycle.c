/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placecycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:20:30 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/05 16:21:52 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	ft_placecycle(t_filler *my_filler)
{
	if (my_filler->cycle == 0)
		ft_placebot(my_filler);
	if (my_filler->cycle == 1)
		ft_placeleft(my_filler);
	if (my_filler->cycle == 2)
		ft_placetop(my_filler);
	if (my_filler->cycle == 3)
		ft_placeright(my_filler);
	my_filler->cycle2++;
	if (my_filler->cycle2 > 1)
	{
		my_filler->cycle++;
		my_filler->cycle2 = 0;
	}
	if (my_filler->cycle > 3)
		my_filler->cycle = 0;
}
