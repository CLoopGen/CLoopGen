#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double black_point = 1000.0;
double intensity = 0.0;
ssize_t black;

static double *histogram_storage;
double *histogram;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (65536 elements for double)
    histogram_storage = (double*)calloc(data_size, sizeof(double));
    if (!histogram_storage) {
        exit(1);
    }
    histogram = histogram_storage;

    // Initialize histogram with non-zero values to control loop termination
    for (size_t i = 0; i < data_size; i++) {
        histogram[i] = 0.5 + 0.5 * (i % 7) / 7.0; // Avoids using sin; simple arithmetic pattern
    }

    black_point = 10000.0; // Set threshold so loop runs long enough (~0.01 sec)
    intensity = 0.0;
}