#include "rsa.h"

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
		numberLen = strlen(number);
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

void remove_newline(char *str, size_t len)
{
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}