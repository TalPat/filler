/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:40:11 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/09 13:41:54 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_filler
{
	char			team;
	char			enemy;
	char			**board;
	char			**token;
	char			**valid;
	unsigned int	mapx;
	unsigned int	mapy;
	unsigned int	tokx;
	unsigned int	toky;
	unsigned int	gameover;
	char			*line;
	int				offx;
	int				offy;
	char			**trim;
	int				placex;
	int				placey;
	int				cycle;
	int				cycle2;
	int				startx;
	int				starty;
}					t_filler;

void				ft_getplayer(t_filler *myfiller);
void				ft_getmap(t_filler *my_filler);
void				ft_updatemap(t_filler *myfiller);
void				ft_gettoken(t_filler *my_filler);
void				ft_updatetoken(t_filler *my_filler);
void				ft_place(t_filler *my_filler);
void				ft_buildvalid(t_filler *my_filler);
void				ft_gettrim(t_filler *my_filler);
void				ft_placetop(t_filler *my_filler);
void				ft_placebot(t_filler *my_filler);
void				ft_placeleft(t_filler *my_filler);
void				ft_placeright(t_filler *my_filler);
void				ft_placecycle(t_filler *my_filler);
void				ft_placebar(t_filler *my_filler, int gap);
void				ft_placevbar(t_filler *my_filler, int gap);
void				ft_placecross(t_filler *my_filler);
void				ft_placebotleft(t_filler *my_filler);

#endif
