#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *histogram;
double sum;
ssize_t i;

void init_vars() {
    size_t num_elements = 256;
    histogram = (double *)calloc(num_elements, sizeof(double));
    if (!histogram) {
        exit(1);
    }
    for (size_t idx = 0; idx < num_elements; idx++) {
        histogram[idx] = 1.0;
    }
    sum = 0.0;
    i = 0;
}