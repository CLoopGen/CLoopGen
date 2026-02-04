#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double *histogram;
double count;
ssize_t i;
ssize_t max;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB to ensure ~0.01s runtime
    histogram = (double*)aligned_alloc(32, data_size);
    if (!histogram) {
        exit(1);
    }

    // Seed and initialize histogram with pseudo-random values
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < data_size / sizeof(double); ++idx) {
        histogram[idx] = ((double)rand()) / RAND_MAX * 1000.0;
    }

    // Initialize loop control and tracking variables
    count = -1.0;
    i = 0;
    max = 0;
}

__attribute__((destructor))
static void cleanup() {
    if (histogram) {
        free(histogram);
    }
}