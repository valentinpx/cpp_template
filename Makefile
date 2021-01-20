##
## EPITECH PROJECT, 2021
## Valentin Sene's CPP template
## File description:
## Makefile with valgrind and gtest support
##

tests_run:
	rm -rf tests/build *.gcov
	mkdir tests/build
	cd tests/build
	cmake -B tests/build tests
	make -C tests/build
	gcov tests/build/CMakeFiles/executeTests.dir/tests.cpp.gcno
	./tests/build/executeTests

.PHONY: tests_run
