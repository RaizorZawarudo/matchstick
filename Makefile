##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Task01
##
CFLAGS = -g3 -W -Wall -Wextra

SRC	=	main.c \
	game_setup.c \
	display_game_board.c \
	play_a_round.c \
	round_check.c \
	ai_plays.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME) clean

$(NAME):	$(OBJ)
	cd lib/my/ && make
	cd ../..
	gcc -o $(NAME) $(OBJ) -I./include -L./lib -lmy

clean:
	cd lib/my && make clean
	cd ../..
	rm -f $(OBJ)

fclean:	clean
	cd lib/my && make fclean
	cd ../..
	rm -f $(NAME)
re: fclean all

unit_test:
	gcc -lcriterion

.PHONY: all clean fclean re