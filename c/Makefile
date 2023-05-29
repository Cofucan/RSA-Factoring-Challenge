CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89

betty-all:
	betty monty.h *.c

factor:
	gcc $(CFLAGS) factors.c algorithms.c rsa.h -o factors -lm -lgmp -g

test1:
	./factors tests/test00

move:
	mv factors ../