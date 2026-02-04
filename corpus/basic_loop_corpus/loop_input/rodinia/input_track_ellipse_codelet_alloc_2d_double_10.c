#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x = 131072;  // ~131k iterations to target ~0.01 sec runtime
int y = 8;       // stride factor, controls data layout

double *data;
double **pointers;

int i;

void init_vars() {
    const size_t data_size = (size_t)x * y;
    data = (double*)calloc(data_size, sizeof(double));
    if (!data) {
        exit(1);
    }

    pointers = (double**)calloc(x, sizeof(double*));
    if (!pointers) {
        free(data);
        exit(1);
    }
}