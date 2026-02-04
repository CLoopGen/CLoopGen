#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *median;
int *hist;
int i;
double err;
double sum_sq_err;

void init_vars() {
    size_t num_elements = 3 * 256;

    median = (double *)calloc(num_elements, sizeof(double));
    hist = (int *)calloc(num_elements, sizeof(int));

    for (size_t idx = 0; idx < num_elements; idx++) {
        median[idx] = (double)(idx % 1000);
        hist[idx] = (idx % 1000) + 1;
    }

    i = 0;
    err = 0.0;
    sum_sq_err = 0.0;
}