CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89

betty-all:
	betty monty.h *.c

factors:
	gcc $(CFLAGS) 1-factors.c algo* utils.c rsa.h -o factors -lm -lgmp -g

factors_test:
	./factors tests/test00

rsa:
	gcc $(CFLAGS) 2-rsa.c algo* utils.c rsa.h -o rsa -lm -lgmp -g

rsa_test:
	./rsa tests/rsa-15

rsa_debug:
	gdb --args ./rsa tests/rsa-15

clean:
	rm rsa
	rm factors

move:
	mv factors ../