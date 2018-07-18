/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grabline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:23:19 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/06 08:22:45 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_grabline.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_grabline(int fd, char **line)
{
	static t_gnl	*mygnl;
	int				rd;

	mygnl = (t_gnl*)malloc(sizeof(t_gnl));
	mygnl->line = ft_strnew(1);
	mygnl->buff[0] = 0;
	while ((rd = read(fd, mygnl->buff, BUFF_SIZE)))
	{
		if (mygnl->buff[0] == '\n')
			break ;
		mygnl->buff[rd] = 0;
		mygnl->line = ft_strjoin(mygnl->line, mygnl->buff);
	}
	*line = mygnl->line;
	return (1);
}
