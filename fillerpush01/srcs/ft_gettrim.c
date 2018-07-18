/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:37:08 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/05 14:42:31 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include "stdlib.h"

static void	ft_getoffy(t_filler *my_filler)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (my_filler->token[i])
	{
		j = 0;
		while (my_filler->token[i][j])
		{
			if (my_filler->token[i][j] == '*')
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
	my_filler->offy = i;
}

static void	ft_getoffx(t_filler *my_filler)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	j = 0;
	while (my_filler->token[0][j])
	{
		i = 0;
		while (my_filler->token[i])
		{
			if (my_filler->token[i][j] == '*')
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
	my_filler->offx = j;
}

static void	ft_trimbottom(t_filler *my_filler)
{
	int	i;
	int	j;
	int found;

	i = 1;
	found = 0;
	while (!found)
	{
		j = 0;
		while (my_filler->token[my_filler->toky - i][j])
		{
			if (my_filler->token[my_filler->toky - i][j] == '*')
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
	my_filler->token[my_filler->toky - i + 1] = NULL;
}

static void	ft_trimright(t_filler *my_filler)
{
	int	i;
	int	j;
	int found;

	j = 1;
	found = 0;
	while (!found)
	{
		i = 0;
		while (my_filler->token[i])
		{
			if (my_filler->token[i][my_filler->tokx - j] == '*')
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
	i = 0;
	while (my_filler->token[i])
		my_filler->token[i++][my_filler->tokx - j + 1] = '\0';
}

void		ft_gettrim(t_filler *my_filler)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_getoffy(my_filler);
	ft_getoffx(my_filler);
	ft_trimbottom(my_filler);
	ft_trimright(my_filler);
	my_filler->tokx = ft_strlen(my_filler->token[0]) - my_filler->offx;
	while (my_filler->token[i])
		i++;
	my_filler->toky = i - my_filler->offy;
	my_filler->trim = my_filler->token;
	my_filler->token = (char**)malloc(sizeof(char*) * (my_filler->toky + 1));
	my_filler->token[my_filler->toky] = NULL;
	i = my_filler->offy;
	while (my_filler->trim[i])
	{
		my_filler->token[j] = ft_strdup(my_filler->trim[i] + my_filler->offx);
		i++;
		j++;
	}
	free(my_filler->trim);
}
