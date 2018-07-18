/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 11:25:36 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/05 14:29:11 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	t_filler	*my_filler;

	if ((my_filler = (t_filler*)malloc(sizeof(t_filler))))
	{
		ft_getplayer(my_filler);
		while (!(my_filler->gameover))
		{
			if (!(my_filler->board))
			{
				ft_getmap(my_filler);
				ft_gettoken(my_filler);
				ft_gettrim(my_filler);
			}
			else
			{
				ft_updatemap(my_filler);
				ft_updatetoken(my_filler);
				ft_gettrim(my_filler);
			}
			ft_place(my_filler);
		}
	}
	return (0);
}
