/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatemap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:15:10 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/05 14:30:44 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	ft_updatemap(t_filler *my_filler)
{
	int	i;

	i = 0;
	ft_grabline(0, &(my_filler->line));
	ft_grabline(0, &(my_filler->line));
	ft_grabline(0, &(my_filler->line));
	while (ft_isdigit((my_filler->line)[0]))
	{
		ft_strcpy((my_filler->board)[i], (my_filler->line) + 4);
		ft_grabline(0, &(my_filler->line));
		i++;
	}
}
