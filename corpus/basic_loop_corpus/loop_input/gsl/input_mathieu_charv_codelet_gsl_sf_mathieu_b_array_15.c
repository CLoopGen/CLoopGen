#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

double qq = 1.5;
unsigned int even_order = 4096;
unsigned int ii;
unsigned int jj;
double *zz;

void init_vars() {
    const size_t data_size = (size_t)even_order * even_order * sizeof(double);
    zz = (double*)calloc(even_order, even_order * sizeof(double));
    if (!zz) {
        fprintf(stderr, "Failed to allocate memory for zz\n");
        exit(EXIT_FAILURE);
    }
}