/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:11:34 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/09 15:17:15 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int		ft_anyvalid(t_filler *my_filler)
{
	int	i;
	int	j;

	i = 0;
	while (my_filler->valid[i])
	{
		j = 0;
		while (my_filler->valid[i][j])
		{
			if (my_filler->valid[i][j] == '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_smallmap(t_filler *my_filler)
{
	if (my_filler->startx < (int)(my_filler->mapx / 2))
	{
		if (my_filler->cycle % 6 != 0)
			ft_placeright(my_filler);
		else
			ft_placeleft(my_filler);
		my_filler->cycle++;
	}
	else
	{
		if (my_filler->cycle < 6)
		{
			ft_placetop(my_filler);
			my_filler->cycle++;
		}
		else
		{
			ft_placebotleft(my_filler);
			my_filler->cycle = 0;
		}
	}
}

void	ft_placetoken(t_filler *my_filler)
{
	if (my_filler->mapx > 50)
	{
		if (!ft_strchr(my_filler->board[0], my_filler->team))
			ft_placetop(my_filler);
		else if (!ft_strchr(my_filler->board[my_filler->mapy - 1],
				my_filler->team))
			ft_placebot(my_filler);
		else
			ft_placevbar(my_filler, my_filler->mapx / 4);
	}
	else
		ft_smallmap(my_filler);
	if (!ft_anyvalid(my_filler))
	{
		ft_putstr("0 0\n");
		my_filler->gameover = 1;
	}
	else
	{
		ft_putnbr(my_filler->placey - my_filler->offy);
		ft_putchar(' ');
		ft_putnbr(my_filler->placex - my_filler->offx);
		ft_putchar('\n');
	}
}

void	ft_place(t_filler *my_filler)
{
	int	i;

	i = 0;
	ft_buildvalid(my_filler);
	ft_placetoken(my_filler);
}
