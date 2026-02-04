#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *output;
int last;
int originalLast;
int i;
int nextend;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data
    output = (float*)aligned_alloc(32, data_size * sizeof(float));
    
    for (size_t idx = 0; idx < data_size; idx++) {
        output[idx] = (float)(idx + 1);
    }

    originalLast = data_size - 1;
    last = (data_size / 2) - 1;
    nextend = data_size / 2;
}