##
## EPITECH PROJECT, 2021
## Valentin Sene's CPP template
## File description:
## Makefile with valgrind and gtest support
##

SRC =	main.cpp\

OBJ = $(SRC:.cpp=.o)

NAME = a.out

CPPFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CPPFLAGS) $(SRC) -o $(NAME) -I.

debug: clean
debug: CFLAGS += -g
debug: ${NAME}

tests_run:
	rm -rf tests/build
	mkdir tests/build
	cmake -B tests/build tests
	make -C tests/build
	./tests/build/executeTests

clean:
	rm -rf $(OBJ)

fclean:  clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all debug tests_run clean fclean re
