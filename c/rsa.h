#ifndef _RSA_H_
#define _RSA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <gmp.h>

void factorize_unsorted(FILE *file);
void factorize_sorted(FILE *file);
void algo_trivial_div(size_t number);
void algo_trivial_div_gmp(char *numberStr);
void remove_newline(char *str, size_t len);

#endif /* _RSA_H_ */
