##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/pagination.c    	\
        src/my_malloc.c     	\
		src/my_calloc.c 		\
		src/my_realloc.c 		\
		src/my_reallocarray.c 	\
		src/singleton.c 		\
		src/my_free.c 			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

CFLAGS	=	-Wall -Wextra  -fPIC

CPPFLAGS	=	-I./include

CC	=	gcc

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -shared -fPIC -o $(NAME) $(OBJ)

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

.PHONY: all fclean re clean $(NAME) debug tests_run
