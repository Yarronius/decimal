CC=gcc
CFLAGS=-Wall -Wextra -Wformat -Werror -std=c11
COVFLAGS=--coverage
OS=$(shell uname)

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

all: decimal.a

decimal.a: clean
	$(CC) $(CFLAGS) -c decimal.c
	ar rc decimal.a decimal.o
	ranlib decimal.a
	rm -rf decimal.o

test: decimal.a
	$(CC) $(CFLAGS) tests/*.c decimal.a -o test $(CHECK_FLAGS)
	./test

gcov_report: decimal.a
	gcc $(CFLAGS) $(COVFLAGS) tests/*.c decimal.a -o gcov $(CHECK_FLAGS)
	./gcov
	lcov -o gcov.info -c -d .
	genhtml -o report gcov.info
	open report/index.html
	rm -f gcov*

check:
	clang-format -n -style=Google tests/*.c tests/*.h *.c *.h
	clang-format -i -style=Google tests/*.c tests/*.h *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h tests/*.c tests/*.h


ifeq ($(OS), Linux)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./test
else
	leaks -atExit -- ./test
endif

clean:
	rm -rf *.o *.a *.out
	rm -f *.gcda *.gcno *.info
	rm -rf report *.dSYM

	rm -rf test
