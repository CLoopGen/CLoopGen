#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *C;
int ldc;
int i;
int j;
int n1;
int n2;

void init_vars() {
    n1 = 4096;
    n2 = 4096;
    ldc = n2;

    size_t total_elements = n1 * n2;
    size_t total_bytes = total_elements * 2 * sizeof(float);

    float *c_float = (float *)aligned_alloc(32, total_bytes);
    for (size_t idx = 0; idx < total_elements * 2; idx++) {
        c_float[idx] = 0.0f;
    }

    C = (void *)c_float;
}