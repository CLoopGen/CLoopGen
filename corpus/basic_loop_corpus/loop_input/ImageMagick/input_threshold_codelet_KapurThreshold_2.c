#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *histogram;
double *cumulative_histogram;
ssize_t i;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024; // 256 MB total for large enough input
    size_t array_size = data_size / sizeof(double); // Number of double elements

    // Ensure array is at least 256 in size to cover loop index up to 255
    if (array_size < 256) {
        array_size = 256;
    }

    histogram = (double*)calloc(array_size, sizeof(double));
    cumulative_histogram = (double*)calloc(array_size, sizeof(double));

    // Initialize histogram with non-zero values to make computation meaningful
    for (size_t idx = 0; idx < array_size; idx++) {
        histogram[idx] = (double)(rand() % 1000) / 10.0;
    }

    // Initialize cumulative_histogram[0] as base value
    cumulative_histogram[0] = histogram[0];

    // Other variables like 'i' are loop counters and do not need initialization here
}