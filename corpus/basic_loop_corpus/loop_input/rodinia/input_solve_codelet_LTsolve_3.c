#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

u_int dim = 10000000; // Approximately 80 MB for double array

int i;

double *b_ve;

void init_vars() {
    b_ve = (double *)malloc(dim * sizeof(double));
    if (!b_ve) {
        exit(1);
    }

    for (u_int j = 0; j < dim; j++) {
        b_ve[j] = 0.0;
    }

    b_ve[dim - 1000] = 1.0;
}