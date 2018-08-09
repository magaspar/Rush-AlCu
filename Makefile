# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/16 13:57:06 by tduverge     #+#   ##    ##    #+#        #
#    Updated: 2017/12/17 19:13:31 by tduverge    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = alum1

SRC_FILES = alcu_ea_sport.c \
			fill_tab.c \
			ft_onlydigit.c \
			get_next_line.c \
			alum1.c \
			alcu_two_player.c \
			ft_count_matches.c \
			ft_remove.c \
			ft_trans.c \
			alcu_single_ia.c \
			ft_ask_matches.c \
			ft_ask_yes_no.c \
			ft_putbatman.c

SRC = $(addprefix src/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

HEADS = ../header/alum1.h ../header/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) $(FLAGS) -ggdb -o $(NAME) $(OBJ) $(LIBFT)

./srcs/%.o: ./src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C ./libft/
	rm -f $(NAME)

re: fclean all
	make fclean -C ./libft/
