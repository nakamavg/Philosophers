# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 18:28:20 by dgomez-m          #+#    #+#              #
#    Updated: 2024/03/27 13:54:27 by dgomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= Philo
CFLAGS		:= -Wall -Wextra -Werror 
INCLUDE 	:= includes/philo.h
SRC 		:= srcs/philo.c srcs/utils.c srcs/routine.c srcs/threads.c


all:$(NAME)

$(NAME): $(SRC) $(INCLUDE)
	mkdir -p bin
	cc  $(CFLAGS)  -lpthread   $(SRC) -o $(NAME) 

clean:
	rm -rf bin
fclean: clean
	rm -rf $(NAME)
	
re: clean all 
.PHONY: all clean fclean re