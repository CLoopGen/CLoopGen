#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64

float *C;
int ldc;
int i;
int j;
int n1;
int n2;

void init_vars() {
    size_t total_elements;
    size_t data_size_bytes;

    n1 = 2048;
    n2 = 2048;
    ldc = n2;

    total_elements = (size_t)ldc * n1;
    data_size_bytes = total_elements * 2 * sizeof(float);

    C = aligned_alloc(32, data_size_bytes);
    if (!C) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements * 2; idx++) {
        C[idx] = -1.0f;
    }
}