# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/08/19 16:12:56 by event            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM				= lem-in
LIB				= libft/libft.a
FLAGS			= -Wall -Werror -Wextra
FILES			= main.c graph.c display.c init.c connect.c

all: clean $(LIB) $(LEM)
$(LIB):
	make -s -C ./libft
$(LEM) : $(LIB)
	gcc $(FLAGS) $(FILES) $(LIB) -o $(LEM)
clean :
	rm -f $(LEM)
fclean : clean
	rm -f $(LIB)
norm :
	norminette $(FILES) *.h
re : fclean all
