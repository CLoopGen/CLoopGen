#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t N = 65536;
size_t stride = 16;
size_t i;
double *data;
int status;

void init_vars() {
    // Allocate data array to be N * stride in size
    data = (double *)aligned_alloc(sizeof(double), N * stride * sizeof(double));
    if (!data) {
        status = -1;
        return;
    }

    // Initialize the array such that data[i] == 12345. + i, except when i % stride == 0
    for (size_t idx = 0; idx < N * stride; idx++) {
        if (idx % stride == 0) {
            data[idx] = 0.0; // arbitrary value, will be skipped in loop
        } else {
            data[idx] = 12345. + idx;
        }
    }

    // Reset status
    status = 0;
}