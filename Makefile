##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	

OBJ	=	libmy_malloc.o

NAME	=	libmy_malloc.so

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=

CC	=	gcc

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC) -fPIC -o $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -shared

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all $(NAME) debug

debug:	CPPFLAGS += -g3
debug:	re

tests_run: SRC += tests/tests.cpp
tests_run: LDFLAGS += -lcriterion --coverage
tests_run: CPPFLAGS += -iquote./tests/
tests_run: CFLAGS := $(filter-out -Werror, $(CFLAGS))
tests_run: SRC := $(filter-out main.c, $(SRC))
tests_run: NAME := unit_tests
tests_run:
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(CPPFLAGS)
	./$(NAME)

.PHONY: all fclean re clean $(NAME) debug
