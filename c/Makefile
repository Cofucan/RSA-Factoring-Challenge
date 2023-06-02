CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89

betty-all:
	betty monty.h *.c

factors:
	gcc $(CFLAGS) 1-factors.c algo* utils.c rsa.h -o factors -lm -lgmp -g

test_factors:
	./factors tests/test00

rsa:
	gcc $(CFLAGS) 2-rsa.c algo* utils.c rsa.h -o rsa -lm -lgmp -g

test_rsa:
	./rsa tests/rsa15

move:
	mv factors ../