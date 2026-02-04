#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *distortion;
ssize_t i;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // ~256MB of data
    distortion = (double*)aligned_alloc(32, data_size);
    if (!distortion) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size / sizeof(double); idx++) {
        distortion[idx] = 0.5; // arbitrary initial value in valid range
    }
}

__attribute__((destructor))
static void cleanup() {
    if (distortion) {
        free(distortion);
    }
}