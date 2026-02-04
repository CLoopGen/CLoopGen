#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *coeff;
int size;
double x;
double sum;
int i;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(double); // ~512MB of data to target ~0.01s runtime
    coeff = (double*)aligned_alloc(32, size * sizeof(double));
    if (!coeff) exit(1);

    for (int j = 0; j < size; ++j) {
        coeff[j] = 1.0 + (j % 7); 
    }
    x = 1.5;
    sum = coeff[size - 1];
    i = size - 2;
}