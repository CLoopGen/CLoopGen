#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *histogram;
double *probability;
ssize_t i;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024; // 256MB total for arrays
    size_t num_elements = data_size / (2 * sizeof(double)); // Each array gets half

    histogram = (double*)calloc(num_elements, sizeof(double));
    probability = (double*)calloc(num_elements, sizeof(double));

    if (!histogram || !probability) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        histogram[idx] = (double)(idx % 256) + 1.0;
    }
}