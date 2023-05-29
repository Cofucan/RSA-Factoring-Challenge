#pragma once

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