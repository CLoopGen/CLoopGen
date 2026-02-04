#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double *median;
int *hist;
int i;
double err;
double sum_sq_err;

void init_vars() {
    size_t num_elements = 3 * 256;
    hist = (int *)aligned_alloc(32, num_elements * sizeof(int));
    median = (double *)aligned_alloc(32, num_elements * sizeof(double));

    for (size_t idx = 0; idx < num_elements; idx++) {
        hist[idx] = (int)(idx % 256);
        median[idx] = (double)(idx % 256) + 0.5;
    }

    i = 0;
    err = 0.0;
    sum_sq_err = 0.0;
}