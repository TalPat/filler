# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpatter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 11:09:16 by tpatter           #+#    #+#              #
#    Updated: 2018/07/09 16:09:29 by tpatter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	filler
SRC		=	srcs/main.c\
			srcs/ft_getplayer.c\
			srcs/ft_getmap.c\
			srcs/ft_gettoken.c\
			srcs/ft_updatemap.c\
			srcs/ft_updatetoken.c\
			srcs/ft_place.c\
			srcs/ft_buildvalid.c\
			srcs/ft_gettrim.c\
			srcs/ft_placetop.c\
			srcs/ft_placebot.c\
			srcs/ft_placeleft.c\
			srcs/ft_placeright.c\
			srcs/ft_placecycle.c\
			srcs/ft_placebar.c\
			srcs/ft_placevbar.c\
			srcs/ft_placecross.c\
			srcs/ft_placebotleft.c
OBJ		:=	$(SRC:srcs%.c=.%.o)
HEADER	=	includes
INCLUDES = -I ./libft/includes -I ./includes
FLAGS	=	-Wall -Werror -Wextra
LIBDIR	=	./libft
LIBFT	=	$(LIBDIR)/libft.a
STATLIB	=	statlibf


all: $(NAME)
$(NAME): lib
	gcc -c $(FLAGS) $(SRC) $(INCLUDES) #-L. $(LIBFT)
	gcc -o $(NAME) $(OBJ) -L. $(LIBFT)

lib:
	make re -C ./libft
	make clean -C ./libft
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
