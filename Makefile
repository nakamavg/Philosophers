# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 18:28:20 by dgomez-m          #+#    #+#              #
#    Updated: 2024/03/26 18:52:50 by dgomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= Philo
CFLAGS		:= -Wall -Wextra -Werror 
LIBFT_PATH	:= libs/libft
INCLUDE 	:= includes/philo.h
SRC 		:= srcs/main.c


all:$(NAME)

$(NAME): $(SRC) $(INCLUDE)
	mkdir -p bin
	make -C $(LIBFT_PATH) 
	mv $(LIBFT_PATH)/libft.a bin/
	cc  $(CFLAGS)  -lpthread bin/libft.a  $(SRC) -o $(NAME) 

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf bin
fclean: clean
	rm -rf $(NAME)
	
re: clean all 
.PHONY: all clean fclean re