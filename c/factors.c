#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <gmp.h>

void factorize_unsorted(FILE *file);
void factorize_sorted(FILE *file);
void algo_trival_div(size_t number);
void remove_newline(char *str, size_t len);
void algo_trival_div_gmp(char *numberStr);

int main(int argc, char *argv[])
{
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (access(argv[1], R_OK) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("");
		exit(EXIT_FAILURE);
	}

	factorize_unsorted(file);
	/* factorize_sorted(file); */

	fclose(file);

	return (0);
}

void factorize_unsorted(FILE *file)
{
	size_t num, numberLen = 0;
	char *number = NULL;

	while (getline(&number, &numberLen, file) != -1)
	{
		printf("len -> %lu\n", numberLen);
		if (numberLen < 9)
		{
			num = atoi(number);
			algo_trival_div(num);
		}
		else
		{
			remove_newline(number, numberLen);
			algo_trival_div_gmp(number);
		}
	}

	free(number);
}

void factorize_sorted(FILE *file)
{
	(void) file;
}

void algo_trival_div(size_t number)
{
	size_t divisor;
	size_t max_divisor;
	size_t p = 0, q = 0;

	max_divisor = (size_t) sqrt(number);

	for (divisor = 2; (q == 0 && divisor <= max_divisor); divisor++)
	{
		if (number % divisor == 0)
		{
			p = divisor;
			q = number / divisor;
		}
	}

	if (p != 0 && q != 0)
	{ /* If factors are found */
		printf("%lu=%lu*%lu\n", number, q, p);
	}
}

void algo_trival_div_gmp(char *numberStr)
{
	int base, success, q_cmp, div_cmp;
	mpz_t number, divisor, max_divisor, remainder, p, q;

	/* Initialize the pointers to the GMP data structure */
	mpz_init(number);
	mpz_init(divisor);
	mpz_init(max_divisor);
	mpz_init(remainder);
	mpz_init(p);
	mpz_init(q);
	
	/* Initialize the 2 factor variables to 0 */
	mpz_set_ui(p, 0);
	mpz_set_ui(q, 0);

	/* Convert the large number from string and store it in `number` variable */
	base = 10;
	success = mpz_set_str(number, numberStr, base);
	assert (success == 0);

	/* Get the square root of our number, that will represent the largest possible factor */
	mpz_sqrt(max_divisor, number);

	mpz_set_ui(divisor, 2);
	q_cmp = mpz_cmp_ui(q, 0);
	div_cmp = mpz_cmp(divisor, max_divisor);

	while (q_cmp == 0 && (div_cmp < 0 || div_cmp == 0))
	{
		mpz_mod(remainder, number, divisor);
		if (mpz_cmp_ui(remainder, 0) == 0)
		{
			mpz_set(p, divisor);
			mpz_div(q, number, divisor);
			break;
		}
		mpz_add_ui(divisor, divisor, 1);
		div_cmp = mpz_cmp(divisor, max_divisor);
	}

	printf("%s=", numberStr);
	mpz_out_str(stdout, base, q);
	putchar('*');
	mpz_out_str(stdout, base, p);
	putchar('\n');

	mpz_clear(number);
	mpz_clear(divisor);
	mpz_clear(max_divisor);
	mpz_clear(remainder);
	mpz_clear(p);
	mpz_clear(q);
}

void remove_newline(char *str, size_t len)
{
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}