# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/10 18:47:17 by ichyzh            #+#    #+#              #
#    Updated: 2018/06/10 18:47:19 by ichyzh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ichyzh.filler
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC 	= 	main.c \
			iter_map.c \
			initialization.c \
			find_length.c 
LIBFT 	= libft/includes
LIB 	= libft/ -lft
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) -I $(LIBFT) -L $(LIB) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re:  fclean all