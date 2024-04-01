# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 18:28:20 by dgomez-m          #+#    #+#              #
#    Updated: 2024/04/01 01:04:00 by dgomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= Philo_bonus
CFLAGS		:= -Wall -Wextra -Werror 
INCLUDE 	:= includes/philo_bonus.h
SRC 		:= srcs/philo.c   srcs/process.c  srcs/wrapped_sem.c srcs/utils.c srcs/utils2.c \
				srcs/actions.c srcs/routine.c srcs/forks.c


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