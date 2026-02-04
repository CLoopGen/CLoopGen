#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *p;
int i0;
int i1;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (~256MB in bytes)
    p = (float*)aligned_alloc(32, data_size * sizeof(float));
    
    for (size_t idx = 0; idx < data_size; ++idx) {
        p[idx] = (float)(rand()) / RAND_MAX;
    }

    i0 = 2;
    i1 = (int)(data_size - 4);
}